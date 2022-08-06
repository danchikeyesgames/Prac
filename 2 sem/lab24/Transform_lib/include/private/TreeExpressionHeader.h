#ifndef __TREE_EXPRESSION_HEADER_H__
#define __TREE_EXPRESSION_HEADER_H__

typedef struct __ExprOfSymNode tr_SymNode;

typedef struct __Head_ExpressionTree {
    tr_SymNode* start;
    unsigned int value;
} tr_header;

void        tr_SetHeadNode(tr_header* head);
void        tr_ClearTree(tr_header* head);

#endif