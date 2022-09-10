#ifndef __LAB3_VECTOR_H__
#define __LAB3_VECTOR_H__

#include <stddef.h>

typedef struct CVector {
    size_t capacity;
    size_t size;
    int* data;
} vector_t, *vector_ptr;

typedef struct CVector2D {
    size_t capacity;
    size_t size;
    vector_ptr* data;
} vector_2d_t, *vector_2d_ptr;

vector_ptr      create_vector(size_t sz);
vector_2d_ptr   create_vector_2d(size_t sz);
void            vector_push_back(vector_ptr v, int value);
void            vector_2d_push_back(vector_2d_ptr v, vector_ptr ptr);
void            vector_free(vector_ptr);
void            vector_2d_free(vector_2d_ptr);

#endif    // __LAB3_VECTOR_H__