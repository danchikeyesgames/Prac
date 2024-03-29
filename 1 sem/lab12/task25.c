#include <stdio.h>

int pow(int n, int a);

int main(void)
{
    int num = 0, tmpnum = 0, fig, result = 0, i = 0;


    
    while (scanf("%d", &num) != EOF) {
        tmpnum = num;
        while (tmpnum) {
            fig = tmpnum % 10;
            if (!(fig % 2)) {
                if (fig == 0)
                    fig = 9;
                else
                    fig--;
            }
            result = result + fig * pow(10, i);

            tmpnum /= 10;
            i++;
        }

        printf("%d\n", result);
        result = 0, i = 0;
    }
    
    return 0;
}

int pow(int n, int a) {
    if (a == 1)
        return n;

    if (!a)
        return 1;

    return n * pow(n, a - 1);
}