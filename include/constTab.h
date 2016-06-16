#pragma once
#include "util.h"

typedef struct _ConstListNode ConstListNode;

typedef enum
{
    CT_INT,
    CT_STRING,
    CT_REAL
} ConstType;

struct _ConstListNode{
    char label[32];
    ConstType type;
    union {
        char str[256];
        float real;
        int integer;
    } data;

    ConstListNode *next;
};

extern int ct_count;

void ct_insert_int( char *label, int integer);
void ct_insert_real( char *label, float real);
void ct_insert_str( char *label, char *str);

ConstListNode *ct_lookup(char *ct_label);