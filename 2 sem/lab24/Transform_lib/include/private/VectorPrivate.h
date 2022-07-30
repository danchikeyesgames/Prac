#ifndef __VECTOR_PRIVATE_H__
#define __VECTOR_PRIVATE_H__

#include "VectorCh.h"

tr_vector*  vec_CreateVector();
void        vec_add_item(tr_vector* v, char c);
void        vec_delete_item(tr_vector* v, int i);
char        vec_take_item(tr_vector* v);
int         vec_ToInt(const tr_vector* v);
void        vec_StringClear(tr_vector* v);
void        vec_ClearVec(tr_vector* v);

#endif