#include <stdio.h>
#include <stdlib.h>
#include "kp7.h"

int main(void)
{
    int size, num, n = 0, m;
    char c;
    vector *vec;
    vector *vector_int;


    printf("(1) --> Enter Martix in Terminal\n(2) --> read text file");
    if (c == '1') {
        scanf("%d", &m);
        scanf("%d", &n);
        vec = vector_created(n, m);
        vector_int = vector_created(n, m);
        vector_saved(vec, vector_int, n, m);
    } else if (c == '2') {
         printf("Pls, enter new file:\n");
            
    }

    while ((c = getchar()) != EOF) {
        printf("(1) --> print\n(2) --> *");
        if (c == '1')
            vector_print(vec, vector_int, n, m);
        if (c == '2') {
            printf("Enter new Matrix:\n");
        
        }
    
    }
    

    return 0;
}

vector *vector_created(int index, int stolb) {
    vector *num_vec_1; 
    num_vec_1 = (vector*) malloc(sizeof(vector));
    num_vec_1->array = (int*) malloc(stolb * index * sizeof(int));
    num_vec_1->count = stolb * index;
    return num_vec_1;
}

void vector_saved(vector *num_vec_1, vector *num_vec_2, int index, int stolb) {
    int i, j, num, n = 0;
    for (i = 1; i <= index; i++)  {
        for (j = 1; j <= stolb; j++) {
            scanf("%d", &num);
            if (num != 0) {
                num_vec_1->array[n] = (i - 1) * stolb + j - 1;
                num_vec_2->array[n] = num;
                n++;
            }
        }
    }
}

void vector_print(vector *num_vec_1, vector *num_vec_2, int index, int stolb) {
    int i, j, n;
    for (i = 0; i < num_vec_1->count; i++) {
        printf("%d ", num_vec_1->array[i]);
    }
    printf("\n");
    for (i = 0; i < num_vec_2->count; i++) {
        printf("%d ", num_vec_2->array[i]);
    }
    printf("\n");
    for (i = 1, n = 0; i <= index; i++) {
        for (j = 1; j <= stolb; j++) {
            if (num_vec_1->array[n] == (i - 1) * stolb + j - 1) {
                 printf("%d ", num_vec_2->array[n]);
                 n++;
            } else
                printf("0 ");
        }
        printf("\n");
    }
}