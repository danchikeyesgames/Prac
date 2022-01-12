#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int delnum(int k, long long n);

int main(void)
{
    long long num;
    int k = 0, count = 0;

    while ((k = scanf("%lld", &num)) > 0) {
        count = 0;
        for (long long i = num; i > 0; i /= 10)                        
            count++;

        if (count < 2) {
            printf("%lld\n", num);
            continue;
        }
        count = count - count / 2;
        num = delnum(count, num);

        printf("%lld\n", num);
    }

    if (k == 0)
        printf("It's not digital\n");

    return 0;
}

int delnum(int k, long long n)
{   
    int i = 1, j = 1;
    long long result = 0, tmp = 0;
    
    while (n != 0) {
        if (j++ == k) {
            printf("i = %d\n", i);
            n /= 10;
            continue;
        }
        
        tmp = n % 10;
        result = (long long) (tmp * pow(10.0, i - 1)) + result;
        n /= 10;
        i++;
    }

    return result;
}