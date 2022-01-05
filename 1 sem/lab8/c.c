#include <stdio.h>

int main(void)
{
    int num1, num2 = 0, n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num1);
        if (num1 >= 10)
            num2 = num2 + num1;
    }
    
    printf("%d\n", num2);

    return 0;
}
