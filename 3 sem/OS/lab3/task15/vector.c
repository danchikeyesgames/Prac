#include <stdlib.h>

#include "vector.h"

vector_ptr create_vector(size_t sz) {
    vector_ptr new_cvec = (vector_ptr) malloc(sizeof(vector_t));
    new_cvec->capacity = sz;
    new_cvec->size = 0;
    new_cvec->data = (int *) malloc(sizeof(int) * sz);
 
    return new_cvec;
}

vector_2d_ptr create_vector_2d(size_t sz) {
    vector_2d_ptr new_cvec = (vector_2d_ptr) malloc(sizeof(vector_2d_t));
    new_cvec->capacity = sz;
    new_cvec->size = 0;
    new_cvec->data = (vector_ptr *) malloc(sizeof(vector_ptr) * sz);
 
    return new_cvec;
}

void vector_push_back(vector_ptr v, int value) {
    
    if (v->capacity <= v->size) {
        v->data = (int *) realloc(v->data, sizeof(int) * (v->capacity) * 2);
        v->capacity = v->capacity * 2;
    }

    v->data[v->size++] = value;
}

void vector_2d_push_back(vector_2d_ptr v, vector_ptr ptr) {
    
    if (v->capacity <= v->size) {
        v->data = (vector_ptr *) realloc(v->data, sizeof(vector_ptr) * (v->capacity) * 2);
        v->capacity = v->capacity * 2;
    }

    v->data[v->size++] = ptr;
}

void vector_free(vector_ptr v) {
    free(v->data);
    free(v);
}

void vector_2d_free(vector_2d_ptr v) {
    for (int i = 0; i < v->size; ++i) {
        free(v[i].data);
    }

    free(v);
}
