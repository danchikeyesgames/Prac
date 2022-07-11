#ifndef __TREE_EXPRESSIONS_H__
#define __TREE_EXPRESSIONS_H__

#include "TreeExpressionHeader.h"

typedef struct __ExprOfSymNode {
    union {
        char operand;
        int number;
    } value;
    struct __ExprOfSymNode* parent;
    struct __ExprOfSymNode* left;
    struct __ExprOfSymNode* right;
} tr_SymNode;                   // transformation symbol node

tr_SymNode* tr_CreateSymNode();
void        tr_SetNodeOperand();
void        tr_SetNodenumber();
// void        tr_InsertLeftSide(tr_SymNode* InsertNode, tr_SymNode* CurrentNode);
// void        tr_InsertRightSide(tr_SymNode* InsertNode, tr_SymNode* CurrentNode);
tr_SymNode* tr_InsertUpSide(tr_SymNode* CurrentNode);
tr_SymNode* tr_InsertRightExpr(tr_SymNode* CurrentNode);
void        tr_ClearTree(tr_header* head);

#endif