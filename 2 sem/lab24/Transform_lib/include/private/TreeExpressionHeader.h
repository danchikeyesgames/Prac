#ifndef __TREE_EXPRESSION_HEADER_H__
#define __TREE_EXPRESSION_HEADER_H__

typedef struct __ExprOfSymNode {
    union {
        char operand;
        int number;
    } value;
    struct __ExprOfSymNode* parent;
    struct __ExprOfSymNode* left;
    struct __ExprOfSymNode* right;
} tr_SymNode;                   // transformation symbol node

typedef struct __Head_ExpressionTree {
    tr_SymNode* start;
    unsigned int value;
} tr_header;

void        tr_SetHeadNode(tr_header* head);
void        tr_ClearTree(tr_header* head);

#endif