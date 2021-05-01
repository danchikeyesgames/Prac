#include <stdio.h>
#include <stdlib.h>
#include "kp7.h"

int main(void)
{
    int size, num, n = 0, m, n2, m2;
    char c;
    vector *vec = NULL, *vec2 = NULL, *vec3 = NULL;
    vector *vector_int = NULL, *vector_int2 = NULL, *vector_int3 = NULL;

    FILE *myfile;

    printf("(1) --> Enter Martix in Terminal\n(2) --> read text file\n(3) --> print\n(4) --> * with read file\n(0) --> exit\n");

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            continue;
        if (c == '1') {
            scanf("%d", &n);
            scanf("%d", &m);
            if (vec)
                free(vec);
            if (vector_int)
                free(vector_int);
            vec = vector_created(n, m);
            vector_int = vector_created(n, m);
            vector_saved(vec, vector_int, n, m);
        } else if (c == '2') {
            myfile = fopen("Struct.txt", "r");
            fscanf(myfile, "%d%d", &n, &m);
            if (vec)
                free(vec);
            if (vector_int)
                free(vector_int);
            vec = vector_created(n, m);
            vector_int = vector_created(n, m);
            vector_saved_file(vec, vector_int, n, m, myfile);
            fclose(myfile);
        } else if (c == '3')
            vector_print(vec, vector_int, n, m);
        else if (c == '4') {
            printf("Enter new Matrix:\n");
            
            // if (c == '1') {
            //     scanf("%d", &n2);
            //     scanf("%d", &m2);
            //     if (vec2)
            //         free(vec2);
            //     if (vector_int2)
            //         free(vector_int2);
            //     vec2 = vector_created(n2, m2);
            //     vector_int2 = vector_created(n2, m2);
            //     vector_saved(vec2, vector_int2, n2, m2);
            // } else if (c == '2') {
                myfile = fopen("Struct.txt", "r");
                fscanf(myfile, "%d%d", &n2, &m2);
                if (vec2)
                    free(vec2);
                if (vector_int2)
                    free(vector_int2);
                vec2 = vector_created(n2, m2);
                vector_int2 = vector_created(n2, m2);
                vector_saved_file(vec2, vector_int2, n2, m2, myfile);
                fclose(myfile);
            //}
            vector_print(vec2, vector_int2, n2, m2);
            vector_multiplex(vec, vector_int, vec2, vector_int2, vec3, vector_int3, n, n2, m, m2);

        } else if (c == '0')
            break;
        else 
            printf("Incorrect format!\n");
        printf("(1) --> Enter Martix in Terminal\n(2) --> read text file\n(3) --> print\n(4) --> * with read file\n(0) --> exit\n");
    }
    

    return 0;
}

vector *vector_created(int index, int stolb) {
    vector *num_vec_1; 
    num_vec_1 = (vector*) malloc(sizeof(vector));
    num_vec_1->array = (int*) malloc(stolb * index * sizeof(int));
    num_vec_1->count = stolb * index;
    for (int i = 0; i < num_vec_1->count; i++)
        num_vec_1->array[i] = -1;
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
    printf("\n");
}

void vector_saved_file(vector *num_vec_1, vector *num_vec_2, int index, int stolb, FILE * file) {
    int i, j, num, n = 0;
    for (i = 1; i <= index; i++)  {
        for (j = 1; j <= stolb; j++) {
            fscanf(file, "%d", &num);
            if (num != 0) {
                num_vec_1->array[n] = (i - 1) * stolb + j - 1;
                num_vec_2->array[n] = num;
                n++;
            }
        }
    }
}

void vector_multiplex(vector *num1, vector *integer1, vector *num2, vector *integer2, vector *num3, vector *integer3, int n1, int n2, int m1, int m2) {
    int n3, m3, i, j, n = 0, k = 0, sum = 0, p = 0;
    n3 = n1;
    m3 = m2;
    int number1 , number2;
    num3 = vector_created(n3, m3);
    integer3 = vector_created(n3, m3);
    for (i = 1; i <= n3; i++) {
        for (j = 1; j <= m3; j++) {
            for (n = m1 * (i - 1); n < m1 * i; n++) {
                for (k = 0; k < m1 * n1; k++) {
                    if (num1->array[k] == n) {
                        number1 = integer1->array[k];
                        break;
                    }  else {
                        number1 = 0;
                    } 
                }

                for (k = 0; k < m2 * n2; k++) {
                    if (num2->array[k] == (n - m1 * (i - 1)) * m2 + j - 1) {
                        number2 = integer2->array[k];
                        break;
                    } else {
                        number2 = 0;
                    }
                }

                sum = sum + number1 * number2;

            }

            if (sum != 0) {
                num3->array[p] = (i - 1) * m3 + j - 1;
                integer3->array[p] = sum;
                p++;
            }

            sum = 0;
        }
    }
    vector_print(num3, integer3, n3, m3);
}