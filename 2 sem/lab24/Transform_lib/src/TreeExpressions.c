#include "../include/private/TreeExpressions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void clear(tr_SymNode* node);

tr_SymNode* tr_CreateSymNode() {
    tr_SymNode* node = (tr_SymNode *) malloc(sizeof(tr_SymNode));
    node->parent = NULL;
    node->left  = NULL;
    node->right = NULL;

    return node; 
}

void tr_SetHeadNode(tr_header* head) {
    head->start = NULL;
    head->value = 0;
}

void tr_SetNodeOperand(tr_SymNode* node, char c) {
    node->value.operand = c;
    node->flag = 2;
}

void tr_SetNodeSymbol(tr_SymNode* node, char c) {
    node->value.operand = c;
    node->flag = 1;
}

void tr_SetNodenumber(tr_SymNode* node, int num) {
    node->value.number = num;
    node->flag = 0;
}

void tr_InsertLeftSide(tr_SymNode* InsertNode, tr_SymNode* CurrentNode) {
    CurrentNode->left = InsertNode;
    InsertNode->parent = CurrentNode;
}

tr_SymNode* tr_InsertUpSide(tr_SymNode* InsertNode, tr_SymNode* CurrentNode) {
    InsertNode->left    = CurrentNode;
    InsertNode->parent  = NULL;
    CurrentNode->parent = InsertNode;

    return InsertNode;
}

tr_SymNode* tr_InsertRightExpr(tr_SymNode* InsertNode, tr_SymNode* CurrentNode) {
    CurrentNode->right = InsertNode;
    InsertNode->parent = CurrentNode;

    return InsertNode;
}

void tr_SetSymNode(tr_SymNode* CurrentNode, const char* str_line) {
    tr_SymNode* NewNode = (tr_SymNode *) malloc(sizeof(tr_SymNode));
    char c = 0;
    int num = 0;

    if (strlen(str_line) == 1) {
        if (isdigit(*str_line))
            num = atoi(str_line);
        else
            c = *str_line;
    } else {
        num = atoi(str_line);
    }

    if (c == '\0')
        tr_SetNodenumber(NewNode, num);
    else
        tr_SetNodeOperand(NewNode, c);
}

void tr_ClearTree(tr_header* head) {
    if (head->start != NULL) {
        clear(head->start);
    } else {
        printf("TreeEmpty\n");
    }
    
    head->start = NULL;
}

//------------static-functions---------------------

//+++++++++++++++++++++++++++++++++++++++++++++++++

static void clear(tr_SymNode* node) {
    if (node->left != NULL)
        clear(node->left);

    if (node->right != NULL)
        clear(node->right);

    free(node);
}