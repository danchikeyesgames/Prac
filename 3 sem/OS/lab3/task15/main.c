#include <stdio.h>
#include <stdlib.h>

#include "polynomials.h"

#define MAX 4

typedef struct CPolynomArg {
    polynom_multiply_ptr vec;
    size_t start;
    size_t finish;
} polynom_arg_t, *polynom_arg_ptr;

void*   polynom_multiply_thread(void* pol_ptr);
void    program_start(int n);
void    polynom_arg_free(polynom_arg_ptr p);

// int main(int argc, char* argv[]) {
//     vector_t* v1 = create_vector(10);
//     vector_t* v2 = create_vector(10);

//     for (int i = 1; i < 11; ++i) {
//         vector_push_back(v1, i);
//         vector_push_back(v2, i);
//     }

//     polynom_t* p1 = polynom_create(v1);
//     polynom_t* p2 = polynom_create(v2);

//     polynom_t* p3 = polynom_multiply(p1, p2);

//     for (int i = 0; i < p3->size; ++i) {
//         printf("%d ", p3->data->data[i]);
//     }
//     putchar('\n');

//     polynom_free(p1);
//     polynom_free(p2);
//     polynom_free(p3);
//     vector_free(v1);
//     vector_free(v2);

//     return 0;
// }

int main(void) {
    vector_t* v1 = create_vector(MAX);
    vector_t* v2 = create_vector(MAX);
    polynom_multiply_ptr mp = (polynom_multiply_ptr) malloc(sizeof(polynom_multiply_t));
    mp->size = 0;
    mp->data = create_vector_2d(1);

    for (int i = 1; i < MAX; ++i) {
        vector_push_back(v1, i);
        vector_push_back(v2, i);
    }

    polynom_insert(mp, v1);
    polynom_insert(mp, v2);

    polynom_arg_t argt;
    argt.vec = mp;
    argt.start = 0;
    argt.finish = 1;

    polynom_multiply_thread(&argt);

    for (int i = 0; i < MAX + 1; ++i) {
        printf("%d ", argt.vec->data->data[0]->data[i]);
    }
    printf("\n");

    vector_free(v1);
    vector_free(v2);
    polynom_arg_free(&argt);
    return 0;
}

void* polynom_multiply_thread(void* pol_ptr) {
    polynom_arg_ptr p = (polynom_arg_t *) pol_ptr;
    polynom_ptr tmp;
    polynom_ptr p1 = polynom_create(p->vec->data->data[p->start]);
    polynom_ptr p2 = polynom_create(p->vec->data->data[p->finish]);

    tmp = polynom_multiply(p1, p2);
    vector_free(p->vec->data->data[p->start]);
    p->vec->data->data[p->start] = tmp->data;
    
    free(tmp);
    free(p1->data->data);
    free(p2->data->data);
    free(p1->data);
    free(p2->data);
    free(p1);
    free(p2);
}

void polynom_arg_free(polynom_arg_ptr p) {
    for (int i = 0; i < p->vec->data->size; ++i) {
        free(p->vec->data->data[i]->data);
        free(p->vec->data->data[i]);
    }
    free(p->vec->data->data);
    free(p->vec->data);
    free(p->vec);
}

void program_start(int n) {
    
}