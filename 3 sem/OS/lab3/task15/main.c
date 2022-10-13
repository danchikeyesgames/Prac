#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "polynomials.h"

#define MAX 4

typedef struct CPolynomArg {
    polynom_multiply_ptr vec;
    size_t start;
    size_t finish;
} polynom_arg_t, *polynom_arg_ptr;

static unsigned int count_threads = 1;
static unsigned int num_thread    = 1;
static unsigned int offset_thread = 1;

void*   polynom_multiply_thread(void* pol_ptr);
int     program_read_polynoms(polynom_arg_ptr p);
void    polynom_arg_free(polynom_arg_ptr p);

int main(void) {
    polynom_arg_t argt;
    pthread_t* threads_arr;

    argt.vec = (polynom_multiply_ptr) malloc(sizeof(polynom_multiply_t));
    argt.vec->size = 0;
    argt.vec->data = create_vector_2d(1);

    while (program_read_polynoms(&argt) != 1) {
        printf("%d\n", argt.vec->size);
    }

    count_threads = argt.vec->size / 2;
    polynom_arg_ptr argth = (polynom_arg_ptr) malloc(sizeof(polynom_arg_t) * count_threads);
    threads_arr = (pthread_t *) malloc(sizeof(pthread_t) * count_threads);

    int count_operations = 1;

    while (count_operations * 2 < argt.vec->size) {
        count_operations *= 2;
    }

    argth->vec = argt.vec;
    while (offset_thread != count_operations) {
        argth[0].start  = 0;
        argth[0].finish = offset_thread;
        for (int i = 1; i < count_threads; ++i) {
            argth[i].vec = argt.vec;
            argth[i].start = argth[i - 1].start + 2 * offset_thread;
            argth[i].finish = argth[i - 1].finish + 2 * offset_thread;
        }

        for (int i = 0; i < count_threads; ++i) {
            pthread_create(&threads_arr[i], NULL, polynom_multiply_thread, &argth[i]);
        }
    
        for (int i = 0; i < count_threads; ++i) {
            pthread_join(threads_arr[i], NULL);
        }

        offset_thread *= 2;
        count_threads /= 2;
    }

    printf("%d\n", argt.vec->size);
    argth[0].start  = 0;
    argth[0].finish = offset_thread;

    pthread_create(&threads_arr[0], NULL, polynom_multiply_thread, &argth[0]);
    pthread_join(threads_arr[0], NULL);

    for (int i = 0; i < argth[0].vec->data->data[0]->size; ++i) {
        printf("%d ", argth[0].vec->data->data[0]->data[i]);
    }
    printf("\n");

    polynom_arg_free(&argt);
    free(argth);
    free(threads_arr);

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

int program_read_polynoms(polynom_arg_ptr p) {
    vector_t* vtmp = create_vector(MAX);
    char c;
    int num;

    int t = scanf("%d", &num);
    if (t > 0) 
        vector_push_back(vtmp, num);
    else
        return 1;
    while ((c = getchar()) != '\n') {
        scanf("%d", &num);
        vector_push_back(vtmp, num);
    }

    polynom_insert(p->vec, vtmp);
    vector_free(vtmp);
    return 0;
}