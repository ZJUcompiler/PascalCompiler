#include "constTab.h"

int ct_count = 0;

static ConstListNode *ct_head = NULL;
static ConstListNode *ct_tail = NULL;
extern FILE* IR;

void ct_insert_int(char *label, int integer)
{
    ConstListNode *node = (ConstListNode*)malloc(sizeof(ConstListNode));
    assert(strlen(label)<=32);
    strcpy(node->label, label);

    node->data.integer = integer;
    
    node->next = NULL;
    node->type = CT_INT;
    if (ct_tail) ct_tail->next = node;
    ct_tail = node;
    if (!ct_head) 
    {
        ct_head = node;
    }

    ct_count++;
}

void ct_insert_real(char *label, float real)
{
    ConstListNode *node = (ConstListNode*)malloc(sizeof(ConstListNode));
    assert(strlen(label)<=32);
    strcpy(node->label, label);

    node->data.real = real;
    
    node->next = NULL;
    node->type = CT_REAL;
    if (ct_tail) ct_tail->next = node;
    ct_tail = node;
    if (!ct_head) 
    {
        ct_head = node;
    }

    ct_count++;
}

void ct_insert_str(char *label, char *str)
{
    ConstListNode *node = (ConstListNode*)malloc(sizeof(ConstListNode));
    assert(strlen(label)<=32);
    strcpy(node->label, label);

    assert(strlen(str)<=255);
    strcpy(node->data.str+1, str);
    node->data.str[0] = (char)strlen(str);
    node->data.str[strlen(str)] = 0;
    node->next = NULL;
    node->type = CT_STRING;
    if (ct_tail) ct_tail->next = node;
    ct_tail = node;
    if (!ct_head) 
    {
        ct_head = node;
    }
 
    ct_count++;
}

ConstListNode *ct_lookup(char *ct_label)
{
    ConstListNode *p = ct_head;
    while(p)
        if (strcmp(p->label, ct_label)==0)
            return p;
        else
            p = p->next;
    assert(0);  // lookup should never fail
    return NULL;
}

void ct_drop()
{
    ConstListNode *p = ct_head;
    ConstListNode *next = p->next;

    while(next)
    {        
        free(p);
        p = next;
        next = p->next;
    }
    if (p) free(p);
}

void ct_genConst()
{
    ConstListNode *p = ct_head;
    while(p)
    {
        fprintf(IR, "%s\n", p->label);
        switch(p->type)
        {
            case CT_INT:
                fprintf(IR, ".long %d\n", p->data.integer);
                break;
            case CT_STRING:
                fprintf(IR, ".string \"\\%03d%s\\000\"\n", (unsigned int)(p->data.str[0]), &(p->data.str[2]));
                break;
            case CT_REAL:
                fprintf(IR, ".real 0x%x\n", (unsigned int)(p->data.real));
                break;
            default:
                assert(0);
                break;
        }
        p = p->next;
    }
}