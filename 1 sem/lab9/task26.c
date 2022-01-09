#include <stdio.h>
#include <stdlib.h>

#define N 50

int max(int x, int y);
int min(int x, int y);
int mod(int x, int y);

int main(void)
{
    int i, j, l, k = 0, ik, jk, lk;

    scanf("%d %d %d", &i, &j, &l);

    ik = i;
    jk = j;
    lk = l;
    if ((i - 20)*(i - 20) + 4 * j * j <= 100) {
        printf("YES\n" "x = %d \t y = %d \t l = %d \t k = %d\n", i, j, l, k);
    } else {
        for(k = 0; k < N; k++) {
            i = abs( max(mod(min(ik + jk, ik + lk), 30), mod(max(ik + lk, jk + k), 25)) );
            j = mod(abs(ik + k), 10) + mod(abs(jk + k), 10) + mod(abs(lk + k), 10); 
            l = mod((ik*ik*ik + jk*jk*jk + lk*lk*lk - k), 35);

            if ((i - 20)*(i - 20) + 4 * j * j <= 100) {
                printf("YES\n" "x = %d \t y = %d \t l = %d \t k = %d\n", i, j, l, k + 1);
                break;
            }

            ik = i;
            jk = j;
            lk = l;
        }
    }

    if (k == N)
        printf("NO\n");

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