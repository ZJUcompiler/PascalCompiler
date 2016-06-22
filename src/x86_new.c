/*************************************************************************
 > File Name: x86_new.c
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

static int findIDbyIRName(const char *ir_name) {
    if (strcmp(ir_name, "$t0") == 0)
        return EDI;
    else if (strcmp(ir_name, "$t1") == 0)
        return ESI;
    else if (strcmp(ir_name, "$t2") == 0)
        return ECX;
}
static void findRegbyID(int id, char reg[]) {
    switch (id) {
        case EAX:
            strcpy(reg, "eax");
            break;
        case EBX:
            strcpy(reg, "ebx");
            break;
        case ECX:
            strcpy(reg, "ecx");
            break;
        case EDX:
            strcpy(reg, "edx");
            break;
        case EDI:
            strcpy(reg, "edi");
            break;
        case ESI:
            strcpy(reg, "esi");
            break;
        case EBP:
            strcpy(reg, "ebp");
            break;
        case ESP:
            strcpy(reg, "esp");
            break;
        case AX:
            strcpy(reg, "ax");
            break;
        case AL:
            strcpy(reg, "al");
            break;
        case AH:
            strcpy(reg, "ah");
            break;
    }
}
static int labelCheck(char line[]) {
    char *tok;
    tok = strtok(line, " \r\n");
    if (tok != NULL) {
        if (strcmp(tok, ".data") == 0)
            return DATA_ENTER; // now enter data section
        if (tok[0] != '_')
            return -1; // not Label
        switch (tok[2]) {
            case 'M':
                return MAIN_LABEL; // _$MAIN$_: main program
            case 'P':
                return PROC_LABEL; // _$PROC$name1$name2$name3$... : procedure
            case 'F':
                return FUNC_LABEL; // _$FUNC$name1$name2$name3$... : function
            case 'J':
                return JUMP_LABEL; // _$JUMP$_Lx: jump label
            case 'C':
                return CONST_LABEL;// _$CONST$_Lx: const data
        }
    }
    return 0; // empty line
}


static void Parse_2op(char *line, char op1[], char op2[],\
        int *op1_type, int *op2_type) {
    char *tok;
    tok = strtok(line, " \r\n");

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
}

static void Parse_3op(char *line, char op1[], char op2[], char op3[],\
        int *op1_type, int *op2_type, int *op3_type) {
    char *tok;
    tok = strtok(line, " \r\n");

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

static symbolNode loopBack(const char *op) {
    char op_tmp[32];
    strcpy(op_tmp, op);
    symbolNode op_symnode = st_lookup(currSymtab, op_tmp);
    int i;
    fprintf(CODE, "\tmovl\t%%ebp, %%edx\n");
    for (i = 0; i < layerNum; i++) {
        fprintf(CODE, "\tmovl\t(%%edx), %%edx\n");
    }
    return op_symnode;
}

/*
 * store value into register and return register ID
 */
static int getValue(char *op, int op_type, int regID) {
    char reg[8];
    findRegbyID(regID, reg);

    if (isNum(op)) {
        int num = atoi(op);
        fprintf(CODE, "\tmovl\t$%d, %%%s\n", num, reg);
        return regID;
    }
    else if (isReg(op))
        return findIDbyIRName(op);
    else if (isVar(op)) {
        symbolNode symnode = loopBack(op);
        if (op_type == f32 || op_type == i32) {
            fprintf(CODE, "\tmovl\t-%d(%%edx), %%%s\n", symnode->memloc, reg);
            return regID;
        }
        else if (op_type == i8) {
//            fprintf(CODE, "\tmovl\t0, %%eax\n");
            if (regID == AH) {
                fprintf(CODE, "\tmovb\t-%d(%%edx), %%ah\n", symnode->memloc);
                return AH;
            }
            else {
                fprintf(CODE, "\tmovb\t-%d(%%edx), %%al\n", symnode->memloc);
                return AL;
            }
        }
    }
    else if (isLabel(op)) {
        fprintf(CODE, "\tmovl\t%s, %%%s\n", op, reg);
        return regID;
    }
}

/*
 * convert i32 to f32
 * i32 number have to be pushed into the stack
 */
static void convertType() {
    fprintf(CODE, "\tfildl\t0(%%esp)\n");
    fprintf(CODE, "\tfstps\t0(%%esp)\n");
}

static void LT_writeBack(char *op3) {
    int regID;
    char reg[8];
    if (isReg(op3)) {
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg);
        fprintf(CODE, "\tmovzbl\t%%al, %%%s\n", reg);
    }
    else if (isVar(op3)) {
        symbolNode symnode = loopBack(op3);
        fprintf(CODE, "\tmovb\t%%al, -%d(%%edx)\n", symnode->memloc);
    }
}
static void LT_calcu_f32() {
    fprintf(CODE, "\tflds\t0(%%esp)\n");
    fprintf(CODE, "\tflds\t4(%%esp)\n");
    fprintf(CODE, "\tfxch\t%%st(1)\n");
    fprintf(CODE, "\tfucomip\t%%st(1), %%st\n");
    fprintf(CODE, "\tfstp\t%%st(0)\n");
    fprintf(CODE, "\tseta\t%%al\n");
}
static void LT_calcu_i32() {
    fprintf(CODE, "\tcmpl\t%%ebx, %%eax\n");
    fprintf(CODE, "\tsetl\t%%al\n");
}
static void EQ_writeBack(char *op3) {
    int regID;
    char reg[8];
    if (isReg(op3)) {
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg);
        fprintf(CODE, "\tmovzbl\t%%al, %%%s\n", reg);
    }
    else if (isVar(op3)) {
        symbolNode symnode = loopBack(op3);
        fprintf(CODE, "\tmovb\t%%al, -%d(%%edx)\n", symnode->memloc);
    }
}
static void EQ_calcu_f32() {
    fprintf(CODE, "\tflds\t0(%%esp)\n");
    fprintf(CODE, "\tflds\t4(%%esp)\n");
    fprintf(CODE, "\tfxch\t%%st(1)\n");
    fprintf(CODE, "\tfucomip\t%%st(1), %%st\n");
    fprintf(CODE, "\tfstp\t%%st(0)\n");
    fprintf(CODE, "\tsetnp\t%%dl\n");
    fprintf(CODE, "\tmovl\t$0, %%eax\n");
    fprintf(CODE, "\tflds\t0(%%esp)\n");
    fprintf(CODE, "\tflds\t4(%%esp)\n");
    fprintf(CODE, "\tfxch\t%%st(1)\n");
    fprintf(CODE, "\tfucomip\t%%st(1), %%st\n");
    fprintf(CODE, "\tfstp\t%%st(0)\n");
    fprintf(CODE, "\tcmove\t%%edx, %%eax\n");
}
static void logic_calcu_i32(const char *inst, char *op1, char *op2, const char *op3,
                            int op1_type, int op2_type, int op3_type) {
    char reg[8], reg2[8];
    int regID;

    if (strcmp(op1, op3) == 0) {
        regID = getValue(op2, op2_type, EAX);
        findRegbyID(regID, reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
    else if (strcmp(op2, op3) == 0) {
        regID = getValue(op1, op1_type, EAX);
        findRegbyID(regID, reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
    else {
        if (!isReg(op1)) {
            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            regID = getValue(op1, op1_type, findIDbyIRName(op3));
            findRegbyID(regID, reg2);
        }
        else if (!isReg(op2)) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            regID = getValue(op2, op2_type, findIDbyIRName(op3));
            findRegbyID(regID, reg2);
        }
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
}
static void logic_calcu_i8(const char *inst, char *op1, char *op2, char *op3,
                           int op1_type, int op2_type, int op3_type) {
    char reg[8], reg2[8];
    int regID;

    if (strcmp(op1, op3) == 0) {
        regID = getValue(op2, op2_type, EAX);
        if (regID == AL) {
            fprintf(CODE, "\tmovzbl\t%%al, %%eax");
            regID = EAX;
        }
        findRegbyID(regID, reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
    else if (strcmp(op2, op3) == 0) {
        regID = getValue(op1, op1_type, EAX);
        if (regID == AL) {
            fprintf(CODE, "\tmovzbl\t%%al, %%eax");
            regID = EAX;
        }
        findRegbyID(regID, reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
    else {
        if (!isReg(op1)) {
            regID = getValue(op2, op2_type, EAX);
            if (regID == AL) {
                fprintf(CODE, "\tmovzbl\t%%al, %%ebx");
                regID = EBX;
            }
            findRegbyID(regID, reg);
            regID = getValue(op1, op1_type, EAX);
            if (regID == AL) {
                fprintf(CODE, "\tmovzbl\t%%al, %%eax");
                regID = EAX;
            }
            findRegbyID(regID, reg2);
        }
        else if (!isReg(op2)) {
            regID = getValue(op1, op1_type, EAX);
            if (regID == AL) {
                fprintf(CODE, "\tmovzbl\t%%al, %%ebx");
                regID = EBX;
            }
            findRegbyID(regID, reg);
            regID = getValue(op2, op2_type, EAX);
            if (regID == AL) {
                fprintf(CODE, "\tmovzbl\t%%al, %%eax");
                regID = EAX;
            }
            findRegbyID(regID, reg2);
        }
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
}
static void arith_calcu_i32(const char *inst, char *op1, char *op2, const char *op3,
                            int op1_type, int op2_type, int op3_type) {
    int regID;
    char reg[8], reg2[8];
    if (strcmp(op3, op1) == 0) {
        regID = getValue(op2, op2_type, EAX);
        findRegbyID(regID, reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
    else if (strcmp(op3, op2) == 0) {
        regID = getValue(op1, op1_type, EAX);
        findRegbyID(regID, reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
    else {
        if (!isReg(op1)) {
            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            regID = getValue(op1, op1_type, findIDbyIRName(op3));
            findRegbyID(regID, reg2);
        }
        else if (!isReg(op2)) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            regID = getValue(op2, op2_type, findIDbyIRName(op3));
            findRegbyID(regID, reg2);
        }
        fprintf(CODE, "\t%s\t%%%s, %%%s\n", inst, reg, reg2);
    }
}
static void mul_calcu_i32(const char *inst, char *op1, char *op2, const char *op3,
                          int op1_type, int op2_type, int op3_type) {
    int regID;
    char reg[8], reg2[8];
    if (strcmp(op3, op1) == 0) {
        regID = getValue(op2, op2_type, EAX);
        findRegbyID(regID, reg);
        fprintf(CODE, "\tpushl\t%%%s\n", reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\timull\t(%%esp), %%%s\n", reg2);
        fprintf(CODE, "\tsubl\t$4, %%esp\n");
    }
    else if (strcmp(op3, op2) == 0) {
        regID = getValue(op1, op1_type, EAX);
        findRegbyID(regID, reg);
        fprintf(CODE, "\tpushl\t%%%s\n", reg);
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg2);
        fprintf(CODE, "\timull\t(%%esp), %%%s\n", reg2);
        fprintf(CODE, "\tsubl\t$4, %%esp\n");
    }
    else {
        if (!isReg(op1)) {
            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            regID = getValue(op1, op1_type, findIDbyIRName(op3));
            findRegbyID(regID, reg2);
        }
        else if (!isReg(op2)) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            regID = getValue(op2, op2_type, findIDbyIRName(op3));
            findRegbyID(regID, reg2);
        }
        fprintf(CODE, "\timull\t(%%esp), %%%s\n", reg2);
        fprintf(CODE, "\tsubl\t$4, %%esp\n");
    }
}
static void div_calcu_i32(const char *inst, char *op1, char *op2, const char *op3,
                          int op1_type, int op2_type, int op3_type) {
    int regID;
    char reg[8], reg2[8];
    regID = getValue(op2, op2_type, EAX);
    findRegbyID(regID, reg);
    fprintf(CODE, "\tpushl\t%%%s\n", reg);
    regID = getValue(op1, op1_type, EAX);
    findRegbyID(regID, reg);
    if (regID != EAX) {
        fprintf(CODE, "\tmovl\t%%%s, %%eax\n", reg);
        regID = EAX;
    }
    findRegbyID(regID, reg);
    fprintf(CODE, "\tcltd\n");
    fprintf(CODE, "\tidivl\t(%%esp)\n");
    fprintf(CODE, "\tsubl\t$4, %%esp\n");
}
static void arith_calcu_f32(const char *inst, char *op1, char *op2, const char *op3,
                            int op1_type, int op2_type, int op3_type) {
    int regID;
    char reg[8], reg2[8];

    regID = getValue(op1, op1_type, EAX);
    findRegbyID(regID, reg);
    fprintf(CODE, "\tpushl\t%%%s\n", reg);
    regID = getValue(op2, op2_type, EAX);
    findRegbyID(regID, reg);
    fprintf(CODE, "\tpushl\t%%%s\n", reg);

    if (op1_type == f32 && op2_type == f32) {
        fprintf(CODE, "\tflds\t4(%%esp)\n");

        if (strcmp(inst, "fadd") == 0)
            fprintf(CODE, "\tfadds\t(%%esp)\n");
        else if (strcmp(inst, "fsub") == 0)
            fprintf(CODE, "\tfsubs\t(%%esp)\n");
        else if (strcmp(inst, "fmul") == 0)
            fprintf(CODE, "\tfmuls\t(%%esp)\n");
        else if (strcmp(inst, "fdiv") == 0)
            fprintf(CODE, "\tfdivs\t(%%esp)\n");
    }
    else if (op1_type == f32 && op2_type == i32) {
        fprintf(CODE, "\tfildl\t(%%esp)\n");

        if (strcmp(inst, "fadd") == 0)
            fprintf(CODE, "\tfadds\t4(%%esp)\n");
        else if (strcmp(inst, "fsub") == 0) {
            fprintf(CODE, "\tflds\t4(%%esp)\n");
            fprintf(CODE, "\tfsubp\t%%st, %%st(1)\n");
        }
        else if (strcmp(inst, "fmul") == 0)
            fprintf(CODE, "\tfmuls\t4(%%esp)\n");
        else if (strcmp(inst, "fdiv") == 0) {
            fprintf(CODE, "\tflds\t4(%%esp)\n");
            fprintf(CODE, "\tfdivp\t%%st, %%st(1)\n");
        }
    }
    else if (op1_type == i32 && op2_type == f32) {
        fprintf(CODE, "\tfildl\t4(%%esp)\n");

        if (strcmp(inst, "fadd") == 0)
            fprintf(CODE, "\tfadds\t(%%esp)\n");
        else if (strcmp(inst, "fsub") == 0)
            fprintf(CODE, "\tfsubs\t(%%esp)\n");
        else if (strcmp(inst, "fmul") == 0)
            fprintf(CODE, "\tfmuls\t(%%esp)\n");
        else if (strcmp(inst, "fdiv") == 0)
            fprintf(CODE, "\tfdivs\t(%%esp)\n");
    }

    if (isReg(op3)) {
        regID = findIDbyIRName(op3);
        findRegbyID(regID, reg);
        fprintf(CODE, "\tfstps\t(%%esp)\n");
        fprintf(CODE, "\tmovl\t(%%esp), %%%s\n", reg);
    }
    else if (isVar(op3)) {
        symbolNode symnode = loopBack(op3);
        fprintf(CODE, "\tfstps\t-%d(%%edx)\n", symnode->memloc);
    }
}

static void makeStack(int stackSize) {
    fprintf(CODE, "\tpushl\t%%ebp\n");
    fprintf(CODE, "\tmovl\t%%esp, %%ebp\n");
    fprintf(CODE, "\tsubl\t$%d, %%esp\n", stackSize);
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
static void genInst(char *line, FILE *IR) {
    char op1[32], op2[32], op3[32];
    char line_back[256];
    int op1_type, op2_type, op3_type;
    strcpy(line_back, line);
    char *tok = strtok(line, " \r\n");

    int regID;
    char reg[8], reg2[8];
    if (isLT(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (op1_type == f32 && op2_type == f32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);

            LT_calcu_f32();
            LT_writeBack(op3);
            fprintf(CODE, "\taddl\t$8, %%esp\n");
        }
        else if (op1_type == f32 && op2_type == i32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);

            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            convertType();

            LT_calcu_f32();
            LT_writeBack(op3);
            fprintf(CODE, "\taddl\t%%esp, $8\n");
        }
        else if (op1_type == i32 && op2_type == f32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            convertType();

            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);

            LT_calcu_f32();
            LT_writeBack(op3);
            fprintf(CODE, "\taddl\t%%esp, $8\n");
        }
        else if (op1_type == i32 && op2_type == i32) {
            char reg2[8];
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            regID = getValue(op2, op2_type, EBX);
            findRegbyID(regID, reg2);

            LT_calcu_i32();
            LT_writeBack(op3);
        }
    }
    else if (isEQ(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (op1_type == f32 && op2_type == f32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);

            EQ_calcu_f32();
            EQ_writeBack(op3);
            fprintf(CODE, "\taddl\t%%esp, $8\n");
        }
        else if (op1_type == f32 && op2_type == i32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);

            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            convertType();

            EQ_calcu_f32();
            EQ_writeBack(op3);
            fprintf(CODE, "\taddl\t%%esp, $8\n");
        }
        else if (op1_type == i32 && op2_type == f32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);
            convertType();

            regID = getValue(op2, op2_type, EAX);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tpushl\t%%%s\n", reg);

            EQ_calcu_f32();
            EQ_writeBack(op3);
            fprintf(CODE, "\taddl\t%%esp, $8\n");
        }
        else if (op1_type == i32 && op2_type == i32) {
            regID = getValue(op1, op1_type, EAX);
            findRegbyID(regID, reg);
            regID = getValue(op2, op2_type, EBX);
            findRegbyID(regID, reg2);

            fprintf(CODE, "\tcmpl\t%s, %s\n", reg2, reg);
            fprintf(CODE, "\tsete\t%%al\n");
            EQ_writeBack(op3);
        }
        else if (op1_type == i8 && op2_type == i8) {
            if (!isReg(op1) && !isReg(op2)) {
                regID = getValue(op1, op1_type, AL);
                findRegbyID(regID, reg);
                regID = getValue(op2, op2_type, AH);
                findRegbyID(regID, reg2);
                fprintf(CODE, "\tcmpb\t%%%s, %%%s\n", reg2, reg);
                fprintf(CODE, "\tsete\t%%al\n");
            }
            else {
                regID = getValue(op1, op1_type, EAX);
                if (regID == AL) {
                    fprintf(CODE, "\tmovzbl\t%%al, %%ebx\n");
                    regID = EBX;
                }
                findRegbyID(regID, reg);
                regID = getValue(op2, op2_type, EAX);
                if (regID == AL) {
                    fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
                    regID = EAX;
                }
                findRegbyID(regID, reg2);
                fprintf(CODE, "\tcmpl\t%%%s, %%%s\n", reg, reg2);
                fprintf(CODE, "\tsete\t%%al\n");

            }
            EQ_writeBack(op3);
        }
    }
    else if (isXOR(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (op1_type == i32 && op2_type == i32) {
            if (isReg(op3)) {
                logic_calcu_i32("xorl", op1, op2, op3, op1_type, op2_type, op3_type);
            }
            else if (isVar(op3)) {
                logic_calcu_i32("xorl", op1, op2, "$t2", op1_type, op2_type, op3_type);
                symbolNode  symnode = loopBack(op3);
                fprintf(CODE, "\tmovl\t%%ecx, -%d(%%edx)\n", symnode->memloc);
            }
        }
        else if (op1_type == i8 && op2_type == i8) {
            if (isReg(op3)) {
                logic_calcu_i8("xorl", op1, op2, op3, op1_type, op2_type, op3_type);
            }
            else if (isVar(op3)) {
                logic_calcu_i8("xorl", op1, op2, op3, op1_type, op2_type, op3_type);
                symbolNode  symnode = loopBack(op3);
                fprintf(CODE, "\tmovb\t%%al, -%d(%%edx)\n", symnode->memloc);
            }
        }
    }
    else if (isOR(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (op1_type == i32 && op2_type == i32) {
            if (isReg(op3)) {
                logic_calcu_i32("orl", op1, op2, op3, op1_type, op2_type, op3_type);
            }
            else if (isVar(op3)) {
                logic_calcu_i32("orl", op1, op2, "$t2", op1_type, op2_type, op3_type);
                symbolNode  symnode = loopBack(op3);
                fprintf(CODE, "\tmovl\t%%ecx, -%d(%%edx)\n", symnode->memloc);
            }
        }
        else if (op1_type == i8 && op2_type == i8) {
            if (isReg(op3)) {
                logic_calcu_i8("orl", op1, op2, op3, op1_type, op2_type, op3_type);
            }
            else if (isVar(op3)) {
                logic_calcu_i8("orl", op1, op2, op3, op1_type, op2_type, op3_type);
                symbolNode  symnode = loopBack(op3);
                fprintf(CODE, "\tmovb\t%%al, -%d(%%edx)\n", symnode->memloc);
            }
        }
    }
    else if (isAND(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (op1_type == i32 && op2_type == i32) {
            if (isReg(op3)) {
                logic_calcu_i32("andl", op1, op2, op3, op1_type, op2_type, op3_type);
            }
            else if (isVar(op3)) {
                logic_calcu_i32("andl", op1, op2, "$t2", op1_type, op2_type, op3_type);
                symbolNode  symnode = loopBack(op3);
                fprintf(CODE, "\tmovl\t%%ecx, -%d(%%edx)\n", symnode->memloc);
            }
        }
        else if (op1_type == i8 && op2_type == i8) {
            if (isReg(op3)) {
                logic_calcu_i8("andl", op1, op2, op3, op1_type, op2_type, op3_type);
            }
            else if (isVar(op3)) {
                logic_calcu_i8("andl", op1, op2, op3, op1_type, op2_type, op3_type);
                symbolNode  symnode = loopBack(op3);
                fprintf(CODE, "\tmovb\t%%al, -%d(%%edx)\n", symnode->memloc);
            }
        }
    }
    else if (isADD(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (isReg(op3)) {
            arith_calcu_i32("addl", op1, op2, op3, op1_type, op2_type, op3_type);
        }
        else if (isVar(op3)) {
            arith_calcu_i32("addl", op1, op2, "$t2", op1_type, op2_type, op3_type);
            symbolNode  symnode = loopBack(op3);
            fprintf(CODE, "\tmovl\t%%ecx, -%d(%%edx)\n", symnode->memloc);
        }
    }
    else if (isSUB(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (isReg(op3)) {
            arith_calcu_i32("subl", op1, op2, op3, op1_type, op2_type, op3_type);
        }
        else if (isVar(op3)) {
            arith_calcu_i32("subl", op1, op2, "$t2", op1_type, op2_type, op3_type);
            symbolNode  symnode = loopBack(op3);
            fprintf(CODE, "\tmovl\t%%ecx, -%d(%%edx)\n", symnode->memloc);
        }
    }
    else if (isMUL(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (isReg(op3)) {
            mul_calcu_i32("imull", op1, op2, op3, op1_type, op2_type, op3_type);
        }
        else if (isVar(op3)) {
            mul_calcu_i32("imull", op1, op2, "$t2", op1_type, op2_type, op3_type);
            symbolNode  symnode = loopBack(op3);
            fprintf(CODE, "\tmovl\t%%eax, -%d(%%edx)\n", symnode->memloc);
        }
    }
    else if (isDIV(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (isReg(op3)) {
            div_calcu_i32("idivl", op1, op2, op3, op1_type, op2_type, op3_type);
            regID = findIDbyIRName(op3);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tmovl\t%%eax, %%%s\n", reg);
        }
        else if (isVar(op3)) {
            mul_calcu_i32("idivl", op1, op2, "$t2", op1_type, op2_type, op3_type);
            symbolNode  symnode = loopBack(op3);
            fprintf(CODE, "\tmovl\t%%eax, -%d(%%edx)\n", symnode->memloc);
        }
    }
    else if (isMOD(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        if (isReg(op3)) {
            div_calcu_i32("idivl", op1, op2, op3, op1_type, op2_type, op3_type);
            regID = findIDbyIRName(op3);
            findRegbyID(regID, reg);
            fprintf(CODE, "\tmovl\t%%edx, %%%s\n", reg);
        }
        else if (isVar(op3)) {
            mul_calcu_i32("idivl", op1, op2, "$t2", op1_type, op2_type, op3_type);
            symbolNode  symnode = loopBack(op3);
            fprintf(CODE, "\tmovl\t%%edx, -%d(%%edx)\n", symnode->memloc);
        }
    }
    else if (isFADD(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        arith_calcu_f32("fadd", op1, op2, op3, op1_type, op2_type, op3_type);
    }
    else if (isFSUB(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        arith_calcu_f32("fsub", op1, op2, op3, op1_type, op2_type, op3_type);
    }
    else if (isFMUL(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        arith_calcu_f32("fmul", op1, op2, op3, op1_type, op2_type, op3_type);
    }
    else if (isFDIV(tok)) {
        Parse_3op(line_back, op1, op2, op3, &op1_type, &op2_type, &op3_type);
        arith_calcu_f32("fdiv", op1, op2, op3, op1_type, op2_type, op3_type);
    }
    else if (isASN(tok)) {
        Parse_2op(line_back, op1, op2, &op1_type, &op2_type);
        regID = getValue(op1, op1_type, EAX);
        if (isReg(op2)) {
            if (regID == AL) {
                fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
                regID = EAX;
            }
            if (findIDbyIRName(op2) != regID) {
                findRegbyID(regID, reg);
                findRegbyID(findIDbyIRName(op2), reg2);
                fprintf(CODE, "\tmovl\t%%%s, %%%s\n", reg, reg2);
            }
        }
        else if (isVar(op2)) {
            symbolNode symnode = loopBack(op2);
            if (regID == AL) {
                fprintf(CODE, "\tmovb\t%%al, -%d(%%edx)\n", symnode->memloc);
            }
            else {
                findRegbyID(regID, reg);
                fprintf(CODE, "\tmovl\t%%%s, -%d(%%edx)\n", reg, symnode->memloc);
            }
        }
    }
    else if (isJMP(tok)) {
        tok = strtok(NULL, " \n\r");
        fprintf(CODE, "\tjmp\t%s\n", tok);
    }
    else if (isIF(tok)) {
        tok = strtok(NULL, " \r\n");
        tok = strtok(NULL, " \r\n");
        op1_type = i8;
        strcpy(op1, tok);
        regID = getValue(op1, op1_type, EAX);
        if (regID == AL) {
            fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
            regID = EAX;
        }
        findRegbyID(regID, reg);
        tok = strtok(NULL, " \r\n");
        fprintf(CODE, "\tcmpl\t$0, %%%s\n", reg);
        fprintf(CODE, "\tje\t%s\n", tok);
    }
    else if (isARG(tok)) {
        char argList[256][32];
        int argType[256];
        char line[512];
        int argNum = 0, type;

        tok = strtok(NULL, " \r\n");
        strcpy(argList[argNum], tok);
        tok = strtok(NULL, " \r\n");
        if (strcmp(tok, "i32") == 0)
            type = i32;
        else if (strcmp(tok, "f32") == 0)
            type = f32;
        else if (strcmp(tok, "i8") == 0)
            type = i8;
        argType[argNum++] = type;

        while (1) {
            fgets(line, sizeof(line), IR);
            tok = strtok(line, " \r\n");
            if (strcmp(tok, "arg") == 0) {
                strcpy(argList[argNum++], tok);
                continue;
            }
            else if (strcmp(tok, "call") == 0) {
                int i;
                for (i = argNum - 1; i >= 0; i--) {
                    regID = getValue(argList[i], argType[i], EAX);
                    if (regID == AL) {
                        fprintf(CODE, "\tmovzbl\t%%al, %%eax\n");
                        regID = EAX;
                    }
                    findRegbyID(regID, reg);
                    fprintf(CODE, "\tpushl\t%%%s\n", reg);
                }
                tok = strtok(NULL, " \r\n");
                if (isABS(tok)) {
                   fprintf(CODE, "\tcall\t_abs_int\n");
                }
                else if (isCHR(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_chr_int\n");
                }
                else if (isODD(tok)) {
                    fprintf(CODE, "\tcall\t_odd_int\n");
                }
                else if (isORD(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_ord_int\n");
                }
                else if (isPRED(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_pred_int\n");
                }
                else if (isSQR(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_sqr_int\n");
                }
                else if (isSQRT(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_sqrt_int\n");
                }
                else if (isSUCC(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_succ_int\n");
                }
                else if (isREAD(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_read_int\n");
                }
                else if (isWRITE(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_write_int\n");
                }
                else if (isWRITELN(tok)) {
                    // TODO
                    fprintf(CODE, "\tcall\t_writeln_int\n");
                }
                else
                    fprintf(CODE, "\tcall\t%s\n", tok);
                break;
            }
        }
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
        tok = strtok(NULL, "$\r\n");
    }
    return symnode;
}
static void genDataSection(FILE *ir);
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
                genInst(line, IR);
                break;
            case 1:
                if (strlen(currBlock) != 0) {
                    fprintf(CODE, "\tleave\n");
                    fprintf(CODE, "\tret\n");
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
            case 3:
                //tok = strtok(line, " \r\n");
                strcpy(line_back, line);
                line[strlen(line)-1] = '\0';
                if (strlen(currBlock) != 0) {
                    fprintf(CODE, "\tleave\n");
                    fprintf(CODE, "\tret\n");
                    fprintf(CODE, ".LFE%d:\n", currFinID++);
                    fprintf(CODE, "\t.size\t%s, .-%s\n\n", currBlock, currBlock);
                }
                fprintf(CODE, "\t.globl\t %s\n", line);
                fprintf(CODE, "\t.type\t %s,@function\n", line);
                fprintf(CODE, "%s:\n", line);
                strcpy(currBlock, line);

                symbolNode table = getBucketbyName(line_back);
                makeStack(getMaxMemLoc(table->nextBucket));
                break;
            case 4:
                tok = strtok(line, " \r\n");
                fprintf(CODE, "%s:\n", tok);
                break;
            case 5: // enter data section
            case 6:
                fprintf(CODE, "\tleave\n");
                fprintf(CODE, "\tret\n");
                fprintf(CODE, ".LFE%d:\n", currFinID++);
                fprintf(CODE, "\t.size\t%s, .-%s\n\n", currBlock, currBlock);
                return;
        }
    }
}
static void genDataSection(FILE *ir) {
    fprintf(CODE, ".section\t.rodata\n");

    char line[512];
    while (fgets(line, sizeof(line), ir) != 0) {
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

