#include <stdio.h>
#include <stdlib.h>

#define N 50

int main(void)
{
    int i = 18, j = -9, l = 5;
    int ik, jk, lk;

    ik = i;
    jk = j;
    lk = l;
    for (int k = 1; k <= N; k++) {
        i = mod(ik * max(jk, lk), 30) + mod(jk * min(ik, lk), 20) + k;
        j = min(ik, max(jk, min(lk, max(ik - lk, jk - lk))));
        l = sign(k - 10) * abs(ik - jk + lk - k);

        

        ik = i;
        jk = j;
        lk = l;
    }

    return 0;
}