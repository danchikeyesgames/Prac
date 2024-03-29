#include "../include/private/VectorPrivate.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tr_vector*  vec_CreateVector() {
    tr_vector* v = (tr_vector *) malloc(sizeof(tr_vector));
    v->Item = NULL;
    v->length = 0;
}

void vec_add_item(tr_vector* v, char c) {
    size_t len;
    if (v->length == 0) {
        v->Item = (char *) malloc(sizeof(char) * 2);
        v->Item[0] = c;
        v->Item[1] = '\0';
        v->length = 2;
    } else if (strlen(v->Item) + 1 < v->length) {
        len = strlen(v->Item);
        v->Item[len] = c;
        v->Item[len + 1] = '\0';
    } else if (strlen(v->Item) + 1 == v->length) {
        v->length *= 2;
        v->Item = (char *) realloc(v->Item, sizeof(char) * v->length);
        len = strlen(v->Item);
        v->Item[len] = c;
        v->Item[len + 1] = '\0';
    }
}

void vec_delete_item(tr_vector* v, int i) {
    v->Item[i] = '\0';
    for (int j = i; j < strlen(v->Item) + 1; ++j) {
        v->Item[j] = v->Item[j + 1];
    }
}

char vec_take_item(tr_vector* v) {
    char c = v->Item[0];
    vec_delete_item(v, 0);

    return c;
}

int vec_ToInt(const tr_vector* v) {
    int num = atoi(v->Item);
    return num;
}

void vec_StringClear(tr_vector* v) {
    free(v->Item);
    v->length = 0;
    v->Item = NULL;
}

void vec_ClearVec(tr_vector* v) {
    vec_StringClear(v);
    free(v);
}


