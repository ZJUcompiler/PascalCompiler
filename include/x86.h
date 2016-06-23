#pragma once

FILE *CODE;
void genX86Asm(FILE *IR);

#define EAX 1
#define EBX 2
#define ECX 3
#define EDX 4
#define EDI 5
#define ESI 6
#define EBP 7
#define ESP 8

#define AX 11
#define AL 110
#define AH 111

#define MAIN_LABEL 1
#define PROC_LABEL 2
#define FUNC_LABEL 3
#define JUMP_LABEL 4
#define CONST_LABEL 5
#define DATA_ENTER 6


static const int i32 = 0x00;
static const int i8 = 0x01;
static const int f32 = 0x02;
static const int str = 0x03;

extern symbolNode buckets[];
extern int layerNum;
static symbolNode *currSymtab = buckets;

// op
static inline int isNum(const char *op) {
    return (op[0] <= '9') && (op[0] >= '0');
}
static inline int isReg(const char *op) {
    return op[0] == '$';
}
static inline int isLabel(const char *op) {
    return op[0] == '_' && op[1] == '$';
}
static inline int isAddr(const char *op) {
    return op[0] == '&';
}
static inline int isVar(const char *op) {
    return !(isNum(op) || isReg(op) || isLabel(op) || isAddr(op));
}

// comm
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
static inline int isPUSH(const char *comm) {
    return strcmp(comm, "push") == 0;
}
static inline int isPOP(const char *comm) {
    return strcmp(comm, "pop") == 0;
}
static inline int isASN_STR(const char *comm) {
    return strcmp(comm, "asn_str") == 0;
}
static inline int isLOAD(const char *comm) {
    return strcmp(comm, "load") == 0;
}
static inline int isLEA(const char *comm) {
    return strcmp(comm, "lea") == 0;
}
static inline int isSTORE(const char *comm) {
    return strcmp(comm, "store") == 0;
}
static inline int isCALL(const char *comm) {
    return strcmp(comm, "call") == 0;
}
static inline int isARG(const char *comm) {
    return strcmp(comm, "arg") == 0;
}
static inline int isIF_F(const char *comm) {
    return strcmp(comm, "if_f") == 0;
}
static inline int isIF_T(const char *comm) {
    return strcmp(comm, "if_t") == 0;
}
static inline int isJMP(const char *comm) {
    return strcmp(comm, "jmp") == 0;
}
static inline int getMaxMemLoc(symbolNode *table) {
    return table[BUCKET_SIZE]->memloc;
}

// func
static inline int isABS(const char *tok) {
    return strcmp(tok, "abs") == 0;
}
static inline int isCHR(const char *tok) {
    return strcmp(tok, "chr") == 0;
}
static inline int isORD(const char *tok) {
    return strcmp(tok, "ord") == 0;
}
static inline int isODD(const char *tok) {
    return strcmp(tok, "odd") == 0;
}
static inline int isPRED(const char *tok) {
    return strcmp(tok, "pred") == 0;
}
static inline int isSQR(const char *tok) {
    return strcmp(tok, "sqr") == 0;
}
static inline int isSQRT(const char *tok) {
    return strcmp(tok, "sqrt") == 0;
}
static inline int isSUCC(const char *tok) {
    return strcmp(tok, "succ") == 0;
}
static inline int isREAD(const char *tok) {
    return strcmp(tok, "read") == 0;
}
static inline int isWRITE(const char *tok) {
    return strcmp(tok, "write") == 0;
}
static inline int isWRITELN(const char *tok) {
    return strcmp(tok, "writeln") == 0;
}

