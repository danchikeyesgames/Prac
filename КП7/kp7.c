#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size, i, j, num, n1 = 0, n = 0;
    int *vector;
    int * vector_int;
    scanf("%d", &size);
    vector = (int*) malloc(size * size * sizeof(int));
    vector_int = (int*) malloc(size * size * sizeof(int));

    for (i = 1; i <= size; i++)  {
        for (j = 1; j <= size; j++) {
            scanf("%d", &num);
            if (num != 0) {
                vector[n] = (i - 1) * size + j - 1;
                vector_int[n] = num;
                n++;
            }
        }
    }

    for (i = 0; i <= n; i++)
        printf("%d ", vector[i]);

    printf("\n");

    for (i = 0; i <= n; i++)
        printf("%d ", vector_int[i]);

    printf("\n");

    n = 0;

    for (i = 1; i <= size; i++)  {
        for (j = 1; j <= size; j++) {
            if (vector[n] == (i - 1) * size + j - 1) {
                printf("%d ", vector_int[n]);
                n++;
            } else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}