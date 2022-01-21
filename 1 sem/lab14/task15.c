#include <stdio.h>

#define MAX 100

int main(void)
{
    int n, k, nd = 0, x = 0, y = 0, l = 0, m = 0;
    int matrix[MAX][MAX];
    int dir[2] = {-1, 1};

    scanf("%d", &k);
    for (int key = 0; key < k; key++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", matrix[i] + j);

        x = 0;
        y = n - 1;
        nd = 2 * y + 1;
        for (int i = 0, l = 1, m = 0; i < nd; i++) {
            while (i % 2 == 0 ? y != 0 : y != n - 1) {
                printf("%d ", matrix[y][x]);
                y += dir[i % 2];
                x += dir[(i + 1) % 2];
            }
            printf("%d ", matrix[y][x]);
            x += dir[(i + 1) % 2] * m;
            y += dir[(i + 1) % 2] * l;

            if (i % 2 == 0)
                m++;
            else
                l++;
        }
        putchar('\n');
    }

    return 0;
}