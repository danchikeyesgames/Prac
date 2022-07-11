#ifndef __TRANSFORM_TO_TREE_H__
#define __TRANSFORM_TO_TREE_H__

#include "TreeExpressionHeader.h"

tr_header*  tr_CreateTransformedTree(char* input, int max);
void        tr_OutputNormalFormat(tr_header* head);

#endif