#ifndef _UTIL_H_
#define _UTIL_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "globals.h"
TreeNode *newTreeNode(NodeKind kind);
void appendChild(TreeNode *t, TreeNode *child);
TreeNode *newTokenTreeNode(NodeKind kind, char* tokenString);
void printTreeNode(TreeNode* treeNode);
char* getNodeKindString(NodeKind kind);

#endif
