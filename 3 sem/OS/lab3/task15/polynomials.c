#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "polynomials.h"

polynom_ptr polynom_create(vector_ptr v) {
    polynom_ptr new_polynom = (polynom_ptr) malloc(sizeof(polynom_t));
    new_polynom->size = v->size;
    new_polynom->data = (vector_ptr) malloc(sizeof(vector_t));

    memcpy(new_polynom->data, v, sizeof(vector_t));
    new_polynom->data->data = (int *) malloc(sizeof(int) * new_polynom->size);
    memcpy(new_polynom->data->data, v->data, sizeof(int) * new_polynom->size);

    return new_polynom;
}

polynom_ptr polynom_multiply(polynom_ptr v1, polynom_ptr v2) {
    int szwidth = v1->size;
    int szheight = v1->size + v2->size - 1;
    polynom_ptr result = malloc(sizeof(polynom_t));

    int** res = (int **) malloc(sizeof(int *) * szheight);
    for (int i = 0; i < szheight; ++i) {
        res[i] = (int *) malloc(sizeof(int) * szwidth);
        memset(res[i], 0, sizeof(int) * szwidth);
    }

    for (int i = 0; i < szwidth; ++i) {
        for (int j = 0; j < v2->size; ++j) {
            res[i + j][i] = v1->data->data[i] * v2->data->data[j];
        }
    }

    result->size = szheight;
    result->data = create_vector(szheight);
    result->data->capacity = szheight;
    result->data->size = szheight;

    for (int j = 0; j < szheight; ++j) {
        result->data->data[j] = 0;
        for (int i = 0; i < szwidth; ++i) {
            result->data->data[j] += res[j][i]; 
        }
    }

    for (int i = 0; i < szheight; ++i) {
        free(res[i]);
    }
    free(res);

    return result;
}

void polynom_free(polynom_ptr p) {
    vector_free(p->data);
    free(p);
}