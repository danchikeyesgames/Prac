#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int main(void)
{
    int num, matrix[SIZE * SIZE], x, y, x1, y1;

    if (scanf("%d", &num) <= 0)
        exit(1);
    for (int i = 0; i < num * num; i++)
        if (scanf("%d", matrix + i) <= 0)
            exit(1);

    x = 0; y = num - 1;
    while (x != num || y != 0) {
        x1 = x;
        y1 = y;
        if (y > 0) {
            while (y1 != num) {
                printf("%d ", *(matrix + num * y1 + x1));
                y1 += 1;
                x1 += 1;
            }
            y--;
        } else {
            while (x1 != num) {
                printf("%d ", *(matrix + num * y1 + x1));
                y1 += 1;
                x1 += 1;
            }
            x++;
        }
    }

    putchar('\n');

    return 0;
}