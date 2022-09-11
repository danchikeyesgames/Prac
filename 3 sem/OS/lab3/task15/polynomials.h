#ifndef __POLYNOMIALS_H__
#define __POLYNOMIALS_H__

#include <stddef.h>
#include "vector.h"

typedef struct CPolynom {
    size_t size;
    vector_t* data;
} polynom_t, *polynom_ptr;

typedef struct CpolynomMultiply {
    size_t size;
    vector_2d_t* data;
} polynom_multiply_t, *polynom_multiply_ptr;

polynom_ptr polynom_create(vector_ptr v);
polynom_ptr polynom_multiply(polynom_ptr v1, polynom_ptr v2);
void        polynom_insert(polynom_multiply_ptr pol, vector_ptr vec);
void        polynom_free(polynom_ptr p);


#endif    // __POLYNOMIALS_H__