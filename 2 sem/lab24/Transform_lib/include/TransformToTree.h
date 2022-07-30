#ifndef __TRANSFORM_TO_TREE_H__
#define __TRANSFORM_TO_TREE_H__

#include "private/TreeExpressionHeader.h"
#include "private/VectorCh.h"

void        tr_CreateTransformedTree(tr_vector* input, int max, tr_header* head);
void        tr_OutputNormalFormat(tr_header* head);
tr_vector*  tr_CollectNewVector();                    // Collect new vector of char from stdin
void        tr_PrintVector(tr_vector* v);

#endif