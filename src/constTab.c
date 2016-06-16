#include "constTab.h"

int ct_count = 0;

static ConstListNode *ct_head = NULL;
static ConstListNode *ct_tail = NULL;

void ct_insert_int(char *label, int integer)
{
    ConstListNode *node = (ConstListNode*)malloc(sizeof(ConstListNode));
    assert(strlen(label)<=32);
    strcpy(node->label, label);

    node->data.integer = integer;
    
    node->next = NULL;
    if (ct_tail) ct_tail->next = node;
    ct_tail = node;
    if (!ct_head) ct_head = node;

    ct_count++;
}

void ct_insert_real(char *label, float real)
{
    ConstListNode *node = (ConstListNode*)malloc(sizeof(ConstListNode));
    assert(strlen(label)<=32);
    strcpy(node->label, label);

    node->data.real = real;
    
    node->next = NULL;
    if (ct_tail) ct_tail->next = node;
    ct_tail = node;
    if (!ct_head) ct_head = node;    

    ct_count++;
}

void ct_insert_str(char *label, char *str)
{
    ConstListNode *node = (ConstListNode*)malloc(sizeof(ConstListNode));
    assert(strlen(label)<=32);
    strcpy(node->label, label);

    assert(strlen(str)<=255);
    strcpy(node->data.str+1, str);
    node->data.str[0] = strlen(str);
    
    node->next = NULL;
    if (ct_tail) ct_tail->next = node;
    ct_tail = node;
    if (!ct_head) ct_head = node;
 
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