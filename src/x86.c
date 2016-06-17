/*************************************************************************
 > File Name: x86.c
 > Author: Hac
 > Mail: hac@zju.edu.cn
 > Created Time: Thu 16 Jun 2016 09:07:41 PM CST
 ************************************************************************/

#include "stdio.h"
#include <string.h>
#include <symbol.h>
#include <stdlib.h>
#include <x86.h>
#include <globals.h>
FILE *CODE;

static const int i32 = 0x00;
static const int i8 = 0x01;
static const int f32 = 0x02;

extern symbolNode buckets[];
extern int layerNum;
static symbolNode *currSymtab = buckets;

static void regMap(const char *ir_name, char regID[]) {
    if (strcmp(ir_name, "$t0") == 0)
        strcpy(regID, "edi");
    else if (strcmp(ir_name, "$t1") == 0)
        strcpy(regID, "esi");
}
static inline int isLT(const char *comm) {
    return strcmp(comm, "lt") == 0;
}
static inline int isEQ(const char *comm) {
    return strcmp(comm, "eq") == 0;
}
static inline int isXOR(const char *comm) {
    return strcmp(comm, "xor") == 0;
}
static inline int isOR(const char *comm) {
    return strcmp(comm, "or") == 0;
}
static inline int isAND(const char *comm) {
    return strcmp(comm, "and") == 0;
}
static inline int isADD(const char *comm) {
    return strcmp(comm, "add") == 0;
}
static inline int isSUB(const char *comm) {
    return strcmp(comm, "sub") == 0;
}
static inline int isMUL(const char *comm) {
    return strcmp(comm, "mul") == 0;
}
static inline int isDIV(const char *comm) {
    return strcmp(comm, "div") == 0;
}
static inline int isMOD(const char *comm) {
    return strcmp(comm, "mod") == 0;
}
static inline int isFADD(const char *comm) {
    return strcmp(comm, "fadd") == 0;
}
static inline int isFSUB(const char *comm) {
    return strcmp(comm, "fsub") == 0;
}
static inline int isFMUL(const char *comm) {
    return strcmp(comm, "fmul") == 0;
}
static inline int isFDIV(const char *comm) {
    return strcmp(comm, "fdiv") == 0;
}
static inline int isASN(const char *comm) {
    return strcmp(comm, "asn") == 0;
}
static inline int isCALL(const char *comm) {
    return strcmp(comm, "call") == 0;
}
static inline int isARG(const char *comm) {
    return strcmp(comm, "arg") == 0;
}
static inline int isIF(const char *comm) {
    return strcmp(comm, "if_f") == 0;
}
static inline int isJMP(const char *comm) {
    return strcmp(comm, "jmp") == 0;
}
static inline int getMaxMemLoc(symbolNode *table) {
    return table[BUCKET_SIZE]->memloc;
}
static int labelCheck(char line[]) {
    char *tok;
    tok = strtok(line, " \r\n");
    if (tok != NULL) {
        if (tok[0] != '_')
            return -1; // not Label
        switch (tok[2]) {
            case 'M':
                return 1; // _$MAIN$_: main program
            case 'P':
                return 2; // _$PROC$name1$name2$name3$... : procedure
            case 'F':
                return 3; // _$FUNC$name1$name2$name3$... : function
            case 'J':
                return 4; // _$JUMP$_Lx: jump label
            case 'C':
                return 5;// _$CONST$_Lx: const data
        }
    }
    return 0; // empty line
}


static int isNum(char *op) {
    return (op[0] < '9') && (op[0] > '0');
}
static int isReg(char *op) {
    return op[0] == '$';
}
static int isAddr(char *op) {
    return op[0] == '&';
}
static int isPointer(char *op) {
    return op[0] == '*';
}
static inline int isVar(char *op) {
    return !(isNum(op) || isReg(op) || isAddr(op) || isPointer(op));
}

static void instParse(char *line, char op1[], char op2[], char op3[],\
        int *op1_type, int *op2_type, int *op3_type) {
    char *tok;
    char comm[8];
    tok = strtok(line, " \r\n");
    strcpy(comm, tok);

    // op1_type
    tok = strtok(NULL, " \r\n");
    if (strcmp(tok, "i32") == 0)
        *op1_type = i32;
    else if (strcmp(tok, "f32") == 0)
        *op1_type = f32;
    else if (strcmp(tok, "i8") == 0)
        *op1_type = i8;
    // op1
    tok = strtok(NULL, " \r\n");
    strcpy(op1, tok);

    // op2_type
    tok = strtok(NULL, " \r\n");
    if (strcmp(tok, "i32") == 0)
        *op2_type = i32;
    else if (strcmp(tok, "f32") == 0)
        *op2_type = f32;
    else if (strcmp(tok, "i8") == 0)
        *op2_type = i8;
    // op2
    tok = strtok(NULL, " \r\n");
    strcpy(op2, tok);

    if (isASN(comm))
        return;
    // op3_type
    tok = strtok(NULL, " \r\n");
    if (strcmp(tok, "i32") == 0)
        *op3_type = i32;
    else if (strcmp(tok, "f32") == 0)
        *op3_type = f32;
    else if (strcmp(tok, "i8") == 0)
        *op3_type = i8;
    // op3
    tok = strtok(NULL, " \r\n");
    strcpy(op3, tok);
}

static symbolNode loopBack(char *op) {
    symbolNode op_symnode = st_lookup(currSymtab, op);
    int i;
    for (i = 0; i < layerNum; i++) {
        if (i == 0)
            fprintf(CODE, "\tmovl\t(%%ebp), %%eax\n");
        else
            fprintf(CODE, "\tmovl\t(%%eax), %%eax\n");
    }
    return op_symnode;
}
void getValue(char *op, int op_type) {
    if (isNum(op)) {
        int num = atoi(op);
        fprintf(CODE, "\tmovl\t%d, %%edx\n", num);
        fprintf(CODE, "\tpushl\t%%edx\n");
    }
    else if (isReg(op)) {
        char regID[8];
        regMap(op, regID);
        fprintf(CODE, "\tpushl\t%%%s\n", regID);
    }
    else if (isVar(op)) {
        symbolNode symnode = loopBack(op);
        if (op_type == f32 || op_type == i32) {
            fprintf(CODE, "\tmovl\t-%d(%%eax), %%edx\n", symnode->memloc);
            fprintf(CODE, "\tpushl\t%%edx\n");
        }
        else if (op_type == i8) {
            fprintf(CODE, "\tmovl\t0, %%edx\n");
            fprintf(CODE, "\tmovb\t-%d(%%eax), %%dl\n", symnode->memloc);
            fprintf(CODE, "\tpushl\t%%edx\n");
        }
    }
}
static int typeAlign(int op1_type, int op2_type) {
    if (op1_type == i32 && op2_type == f32) {
        fprintf(CODE, "\tfildl\t4(%%esp)\n");
        fprintf(CODE, "\tfstps\t4(%%esp)\n");
        return f32;
    }
    else if (op1_type == f32 && op2_type == i32) {
        fprintf(CODE, "\tfildl\t0(%%esp)\n");
        fprintf(CODE, "\tfstps\t0(%%esp)\n");
        return f32;
    }
    else if (op1_type == f32 && op2_type == f32)
        return f32;
    return i32;
}
void calcu(char *comm, int op1_type, int op2_type, int op3_type) {
    int type;
    if (isADD(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\taddl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = i32;
    }
    else if (isSUB(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tsubl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = i32;
    }
    else if (isMUL(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tmull\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = i32;
    }
    else if (isDIV(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tdivl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = i32;
    }
    else if (isMOD(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tdivl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = i32;
    }
    else if (isFADD(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\taddl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = f32;
    }
    else if (isFSUB(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tsubl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = f32;
    }
    else if (isFMUL(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tmull\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = f32;
    }
    else if (isFDIV(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tdivl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl\t%%esi\n");
        type = f32;
    }
    // ...
    else if (isLT(comm)) {
        type = typeAlign(op1_type, op2_type);
        if (type == i32) {
            fprintf(CODE, "\tpopl\t%%edi\n");
            fprintf(CODE, "\tpopl\t%%esi\n");
            fprintf(CODE, "\tcmpl\t%%edi, %%esi\n");
            fprintf(CODE, "\tsetl\t%%al\n");
            fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
            fprintf(CODE, "\tpushl\t%%eax\n");
        }
        else if (type == f32) {
            fprintf(CODE, "\tflds\t0(%%esp)\n");
            fprintf(CODE, "\tflds\t4(%%esp)\n");
            fprintf(CODE, "\tfxch\t%%st(1)\n");
            fprintf(CODE, "\tfucomip\t%%st(1), %%st\n");
            fprintf(CODE, "\tfstp\t%%st(0)\n");
            fprintf(CODE, "\tseta\t%%al\n");
            fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
            fprintf(CODE, "\tpopl\t%%edi\n");
            fprintf(CODE, "\tpopl\t%%esi\n");
            fprintf(CODE, "\tpushl\t%%eax\n");
        }
    }
    else if (isEQ(comm)) {
        type = typeAlign(op1_type, op2_type);
        if (type == i32 && type == i8) {
            fprintf(CODE, "\tpopl\t%%edi\n");
            fprintf(CODE, "\tpopl\t%%esi\n");
            fprintf(CODE, "\tcmpl\t%%edi, %%esi\n");
            fprintf(CODE, "\tsete\t%%al\n");
            fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
            fprintf(CODE, "\tpushl\t%%eax\n");
        }
        else if (type == f32) {
            fprintf(CODE, "\tflds\t0(%%esp)\n");
            fprintf(CODE, "\tflds\t4(%%esp)\n");
            fprintf(CODE, "\tfucomip\t%%st(1), %%st\n");
            fprintf(CODE, "\tfstp\t%%st(0)\n");
            fprintf(CODE, "\tsete\t%%al\n");
            fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
            fprintf(CODE, "\tpushl\t%%eax\n");
            fprintf(CODE, "\tpopl\t%%edi\n");
            fprintf(CODE, "\tpopl\t%%esi\n");
            fprintf(CODE, "\tpushl\t%%eax\n");
        }
    }
    else if (isXOR(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\txorl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl%%esi\n");
        type = i32;
    }
    else if (isOR(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\torl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl%%esi\n");
        type = i32;
    }
    else if (isXOR(comm)) {
        fprintf(CODE, "\tpopl\t%%edi\n");
        fprintf(CODE, "\tpopl\t%%esi\n");
        fprintf(CODE, "\tandl\t%%edi, %%esi\n");
        fprintf(CODE, "\tpushl%%esi\n");
        type = i32;
    }
    else if (isASN(comm)) {
        // nothing to do
        type = op2_type;
    }
    if (type != f32 && op3_type == f32) {
        fprintf(CODE, "\tfildl\t0(%%esp)\n");
        fprintf(CODE, "\tfstps\t0(%%esp)\n");
    }
}

static void writeBack(char *op3, int op3_type) {
    if (isReg(op3)) {
        char regID[8];
        regMap(op3, regID);
        fprintf(CODE, "\tpopl\t%%%s\n", regID);
    }
    else if (isVar(op3)) {
        symbolNode symnode = loopBack(op3);
        if (op3_type == f32 || op3_type == i32) {
            fprintf(CODE, "\tpopl\t%%edx\n");
            fprintf(CODE, "\tmovl\t%%edx, -%d(%%eax)\n", symnode->memloc);
        }
        else if (op3_type == i8) {
            fprintf(CODE, "\tpopl\t%%edx\n");
            fprintf(CODE, "\tmovb\t%%dl, -%d(%%eax)\n", symnode->memloc);
        }
    }
}

static void makeStack(int stackSize) {
    fprintf(CODE, "pushl %%ebp\n");
    fprintf(CODE, "movl %%esp, %%ebp\n");
    fprintf(CODE, "subl $%d, %%esp\n", stackSize);
}

static void genPreDecl() {
    fprintf(CODE, "\t.file \"test.pas\"\n");
    fprintf(CODE, "###########################\n");
    fprintf(CODE, "#    Generated by PasC    #\n");
    fprintf(CODE, "###########################\n");
    fprintf(CODE, "\n");
}
static void genPostDecl() {
    fprintf(CODE, ".ident\t\"PasC v1.0\"\n");
    fprintf(CODE, ".section\t.node.GNU-stack,\"\",@progbits\n");
}
static void genInst(char *line) {
    char op1[32], op2[32], op3[32];
    int op1_type, op2_type, op3_type;
    char *tok = strtok(line, " \r\n");
    if (isLT(tok) || isEQ(tok) || isXOR(tok) || isOR(tok) || isAND(tok) || isADD(tok)\
            || isSUB(tok) || isMUL(tok) || isDIV(tok) || isMOD(tok) || isFADD(tok)\
            || isFMUL(tok) || isFDIV(tok)) {
        instParse(line, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        getValue(op1, op1_type);
        getValue(op2, op2_type);
        calcu(tok, op1_type, op2_type, op3_type);
        writeBack(op3, op3_type);
    }
    else if (isASN(tok)) {
        instParse(line, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        getValue(op1, op1_type);
        writeBack(op2, op2_type);
    }
    else if (isJMP(tok)) {
        tok = strtok(NULL, " \n\r");
        fprintf(CODE, "\tjmp\t%s\n", tok);
    }
    else if (isIF(tok)) {
        getValue(op1, op1_type);
        tok = strtok(NULL, " \r\n");
        fprintf(CODE, "\tpopl\t%%edx\n");
        fprintf(CODE, "\tcmpb\t0, %%dl\n");
        fprintf(CODE, "\tje\t%s\n", tok);
    }
}
static symbolNode getBucketbyName(char *name) {
    char *tok;
    symbolNode *currBucket = buckets;
    symbolNode symnode;

    // _$FUNC$name1$name2$name3
    tok = strtok(name, "$\r\n"); // _
    tok = strtok(NULL, "$\r\n"); // FUNC
    tok = strtok(NULL, "$\r\n"); // name1
    while (tok != NULL) {
        symnode = st_lookup(currBucket, tok);
        currBucket = symnode->nextBucket;
    }
    return symnode;
}
static void genTextSection(FILE *IR) {
    fprintf(CODE, ".section\t.text\n");
    char line[512], line_back[512], currBlock[128];
    char *tok;
    static int currFinID = 0;

    memset(currBlock, 0, sizeof(currBlock));
    while (fgets(line, sizeof(line), IR) != NULL) {
        strcpy(line_back, line);
        switch (labelCheck(line_back)) {
            case 0:
                break;
            case -1:
                genInst(line);
                break;
            case 1:
                if (strlen(currBlock) != 0) {
                    fprintf(CODE, ".LFE%d:\n", currFinID++);
                    fprintf(CODE, "\t.size\t%s, .-%s\n\n", currBlock, currBlock);
                }
                fprintf(CODE, "\t.globl\tmain\n");
                fprintf(CODE, "\t.type\tmain,@function\n");
                fprintf(CODE, "main:\n");
                strcpy(currBlock, "main");
                makeStack(getMaxMemLoc(buckets));
                break;
            case 2:
                tok = strtok(line, " \r\n");
                if (strlen(currBlock) != 0) {
                    fprintf(CODE, ".LFE%d:\n", currFinID++);
                    fprintf(CODE, "\t.size\t%s, .-%s\n\n", currBlock, currBlock);
                }
                fprintf(CODE, "\t.globl\t %s\n", tok+8);
                fprintf(CODE, "\t.type\t %s,@function\n", tok+8);
                fprintf(CODE, "%s:\n", tok+8);
                strcpy(currBlock, tok);

                symbolNode table = getBucketbyName(tok+8);
                makeStack(getMaxMemLoc(table->nextBucket));
                break;
            case 3:
                fprintf(CODE, "%s:\n", tok);
                break;
            case 4: // enter data section
                fprintf(CODE, ".LFE%d:\n", currFinID++);
                fprintf(CODE, "\t.size\t%s, .-%s\n\n", currBlock, currBlock);
                return;
        }
    }
}
static void genDataSection(FILE *IR) {
    fprintf(CODE, ".section\t.rodata\n");

    char line[512];
    while (fgets(line, sizeof(line), IR) != NULL) {
        fprintf(CODE, "data: %s\n", line);
    }
}
void genX86Asm(FILE *IR) {
    genPreDecl();
    // Code section
    genTextSection(IR);
    // Data section(for const value)
    genDataSection(IR);
    genPostDecl();
}

/* int main(int argc, char *argv[]) */
/* { */
    /* FILE *f = fopen("ir.txt", "rt"); */
    /* CODE = fopen("ir.s", "w"); */
    /* genX86Asm(f); */
    /* fclose(f); */
    /* fclose(CODE); */
    /* return 0; */
/* } */
