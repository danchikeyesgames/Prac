#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;
    struct tree* left;
    struct tree* right;
} node;

node*   CreateTree(int value);
node*   InsertTree(node* root, int value);
void    DeleteTree(node* root);
void    PrintTree(node* root);
int     AmountVertex(node* root);

#endif