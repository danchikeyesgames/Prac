#include <stdio.h>

#define N 100

int main(void)
{
    int matrix[N][N];
    int outmatrix[N][N];
    int n, tmp, k = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < n; i++) {
        k = 0;
        for (int j = 0; j < n; j++) {
            outmatrix[i][j] = matrix[i][0] * matrix[k][0] + matrix[i][1] * matrix[k][1] + matrix[i][2] * matrix[k][2];
            k++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", outmatrix[i][j]);
        putchar('\n');
    }

    return 0;
}