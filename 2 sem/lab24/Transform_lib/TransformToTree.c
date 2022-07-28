#include "include/TransformToTree.h"
#include "include/private/VectorPrivate.h"

// #include <stdio.h>

typedef enum _State {
    ONE, TWO, THREE, FOUR, FIVE
} state;

static int IsSymExp(char c);

void tr_CreateTransformedTree(tr_vector* input, int max, tr_header* head) {

}

tr_vector* tr_CollectNewVector() {            // for sdtin input
    tr_vector* v = vec_CreateVector();
    char sym = 0;
    // state stat = ONE;

    while ((sym = getchar()) != '\n') {
        vec_add_item(v, sym);
    }

}

//------------static-functions---------------------

//+++++++++++++++++++++++++++++++++++++++++++++++++

static int IsSymExp(char c) {

}