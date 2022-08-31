#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PrintTable(int m);
void PrintTableArguments(float x, float y, float yt, int n, int m);
int  FactorialNum(int num);

int main(void) {
    int num_div = 0;
    float epsilon = 1.0f;
    float y;
    float yt;
    int n = 0;
    int m = 0;

    printf("Enter num: ");
    scanf("%d", &num_div);

    while (1.0f + (epsilon / 2) > 1.0f) {
        epsilon /= 2;
    }

    if (num_div > 9 && num_div < 21) {
        m = 2;
    } else if (num_div > 20 && num_div < 31) {
        m = 3;
    } else if (num_div < 100) {
        m = 3;
    } else if (num_div >= 100) {
        m = 4;
    }

    printf("Machine epsilon: %.8f\n", epsilon);
    PrintTable(m);

    float xy = 0.5f / num_div;
    float x = 0.0f;
    n = 1;
    for (int i = 0; i < num_div + 1; ++i) {
        y = 2 * (cos(x)*cos(x) - 1);

        while (fabs(yt - y) > epsilon || n == 100) {
            yt = yt + pow((-1), n) * pow(2 * x, 2 * n) / FactorialNum(2*n);
            n++;
        }

        PrintTableArguments(x, y, yt, n, m);
        x += xy;
        yt = 0.f;
        n = 1;
    }

    return 0;
}

void PrintTable(int m) {
    printf("+%s+-----------------------+-------------+-----+\n", (m + 2) == 4 ? "----" : ((m + 2) == 5 ? "-----" : "------"));
    printf("|%*c%*c|%22s%1c|%10s%3c|%3c%2c|\n", (m+2) % 2 ? (m + 2) / 2 + 1 : (m + 2) / 2, 'x', (m + 2) / 2, ' ', "y = 2(cos(x) ^ 2 - 1)", ' ', "tayler", ' ', 'n', ' ');
    printf("+%s+-----------------------+-------------+-----+\n", (m + 2) == 4 ? "----" : ((m + 2) == 5 ? "-----" : "------"));
}

void PrintTableArguments(float x, float y, float yt, int n, int m) {
    printf("|%3.*f|%6c%+-.8f%6c|%1c%+8.8f%1c|%3d%2c|\n", m, x, y, ' ', ' ', ' ', yt, ' ', n, ' ');
    printf("+%s+-----------------------+-------------+-----+\n", (m + 2) == 4 ? "----" : ((m + 2) == 5 ? "-----" : "------"));
}

int FactorialNum(int num) {
    int n = 1;

    for (int i = 1; i <= num; ++i) {
        n *= i;
    }

    return n;
}