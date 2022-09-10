#include <stdio.h>

#include "polynomials.h"

int main(int argc, char* argv[]) {
    vector_t* v1 = create_vector(10);
    vector_t* v2 = create_vector(10);

    for (int i = 1; i < 11; ++i) {
        vector_push_back(v1, i);
        vector_push_back(v2, i);
    }

    polynom_t* p1 = polynom_create(v1);
    polynom_t* p2 = polynom_create(v2);

    polynom_t* p3 = polynom_multiply(p1, p2);

    for (int i = 0; i < p3->size; ++i) {
        printf("%d ", p3->data->data[i]);
    }
    putchar('\n');

    polynom_free(p1);
    polynom_free(p2);
    polynom_free(p3);
    vector_free(v1);
    vector_free(v2);

    return 0;
}