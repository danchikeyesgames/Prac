#ifndef __TREE_EXPRESSIONS_H__
#define __TREE_EXPRESSIONS_H__

#include "TreeExpressionHeader.h"

typedef struct __ExprOfSymNode {
    union {
        char operand;
        int number;
    } value;
    unsigned int flag;          // type 0 - number, 1 - symbol, 2 - operand
    struct __ExprOfSymNode* parent;
    struct __ExprOfSymNode* left;
    struct __ExprOfSymNode* right;
} tr_SymNode;                   // transformation symbol node

tr_SymNode* tr_CreateSymNode();
void        tr_SetNodeOperand(tr_SymNode* node, char c);
void        tr_SetNodenumber(tr_SymNode* node, int num);
void        tr_SetNodeSymbol(tr_SymNode* node, char c);
void        tr_InsertLeftside(tr_SymNode* InsertNode, tr_SymNode* CurrentNode);
tr_SymNode* tr_InsertUpSide(tr_SymNode* InsertNode, tr_SymNode* CurrentNode);
tr_SymNode* tr_InsertRightExpr(tr_SymNode* InsertNode, tr_SymNode* CurrentNode);
void        tr_SetSymNode(tr_SymNode* CurrentNode, const char* str_line);

#endif