#include <stdio.h>
#include <limits.h>

#define MAX 100

int main(void)
{
    int matrix[MAX][MAX];
    int n, max = INT_MIN , min = INT_MAX, k = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] > max)
                max = matrix[i][j];
            else if (matrix[i][j] < min)
                min = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] == min) {
                k++;
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == max)
                matrix[i][j] = k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");   
    }


    return 0;
}