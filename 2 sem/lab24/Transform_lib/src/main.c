#include <stdio.h>

#include "../include/TransformToTree.h"

int main(void) {
    tr_vector* string = NULL;
    tr_header tree;

    tr_SetHeadNode(&tree);
    string = tr_CollectNewVector();
    // tr_PrintVector(string);
    tr_CreateTransformedTree(string, &tree);
    tr_OutputNormalFormat(&tree);
    tr_PrintTreeFormat(&tree);

    tr_ClearVector(string, 1);
    tr_ClearTree(&tree);
    return 0;
}