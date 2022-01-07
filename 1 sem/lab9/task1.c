#include <stdio.h>
#include <stdlib.h>

#define N 50

int mod(int x, int y);
int max(int x , int y);
int min(int x, int y);
int sign(int x);

int main(void)
{
    int i = 18, j = -9, l = 5;
    int ik, jk, lk, k = 0;

    scanf("%d %d %d", &i, &j, &l);
    ik = i;
    jk = j;
    lk = l;
    if ((i - 10)*(i - 10) + (j - 10)*(j - 10) <= 100 && (i - 10)*(i - 10) + (j - 10)*(j - 10) >= 25) printf("YES\n"
        "x = %2d \t y = %2d \t l = %2d \t k = %2d\n", i, j, l, k);
    else {
        for (k = 0; k < N; k++) {
            i = mod(ik * max(jk, lk), 30) + mod(jk * min(ik, lk), 20) + k;
            j = min(ik, max(jk, min(lk, max(ik - lk, jk - lk))));
            l = sign(k - 10) * abs(ik - jk + lk - k);

            if ((i - 10)*(i - 10) + (j - 10)*(j - 10) <= 100 && (i - 10)*(i - 10) + (j - 10)*(j - 10) >= 25) {
                printf("YES\n");
                break;
            }

            ik = i;
            jk = j;
            lk = l;
        }

        if (k != N)
            printf("x = %2d \t y = %2d \t l = %2d \t k = %2d\n", i, j, l, k + 1);
        else
            printf("NO\n");
    }

    return 0;
}

int mod(int x, int y)
{
    return x - (x / y) * y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x > y ? y : x;
}

int sign(int x)
{
    if (x > 0) return 1;
    if (!x) return 0;
    if (x < 0) return -1;
}