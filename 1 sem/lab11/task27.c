#include <stdio.h>
#include <ctype.h>

int other(char sym);
int ConvertForNum(char sym);
int sign(char sym);
void printnum3(int num);
void printnum7(int num);

typedef enum {
    S01, S02, S03
} state;

int main(void)
{
    int result = 0, tmp, check = 0, num1 = 0, num2 = 0, num3tmp = 0;
    state sx = S01;
    char symbol;

    while ((symbol = getchar()) != EOF) {
        switch(sx) {
            case S01:
                result = 0;

                if (isspace(symbol))
                    sx = S01;
                else if (isdigit(symbol)) {
                    if (check == 2) {
                        num3tmp = num1;
                        num1 = num2;
                    }
                    sx = S02;
                    tmp = ConvertForNum(symbol);
                    result = result * 10 + tmp;
                } else if (sign(symbol))
                    sx = S02;
                else if (!isdigit(symbol))
                    sx = S03;
                break;
            case S02:
                if (isdigit(symbol) && !check) {
                    sx = S02;
                    tmp = ConvertForNum(symbol);
                    result = result * 10 + tmp;
                } else if ((isspace(symbol) || other(symbol)) && !check) {
                    check = 1;
                    sx = S01;
                    num1 = result;
                    result = 0;
                } else if (isdigit(symbol) && check) {
                    sx = S02;
                    tmp = ConvertForNum(symbol);
                    result = result * 10 + tmp;
                } else if ((isspace(symbol) || other(symbol)) && check) {
                    check = 2;
                    sx = S01;
                    num2 = result;
                    result = 0;
                } else if (!isdigit(symbol)) {
                    sx = S03;
                    if (check == 2)
                        num1 = num3tmp;
                }
                break;
            case S03:
                if (isspace(symbol) || other(symbol))
                    sx = S01;
                break;
        }
    } 

    if (check == 2) {
        printf("number3  : ");
        printnum3(num1);
        putchar('\n');
        printf("number7  : ");
        printnum7(num1);
        putchar('\n');
        printf("number11 : %d\n", num1);
    }
    if (check == 1)
        printf("You enter one number\n");
    if (!check)
        printf("Number no found!\n");

    return 0;
}

int other(char sym) {
    return sym == ',' ? 1 : 0;
}

int ConvertForNum(char sym) {
    return (int) sym - 48;
}

int sign(char sym) {
    return (sym == '-' || sym == '+') ? 1 : 0;
}

void printnum3(int num) {
    if (num / 10)
        printnum3(num / 10);

    if (num % 10 == 0)
        printf("00");
    if (num % 10 == 1)
        printf("01");
    if (num % 10 == 2)
        printf("02");
    if (num % 10 == 3)
        printf("10");
    if (num % 10 == 4)
        printf("11");
    if (num % 10 == 5)
        printf("12");
    if (num % 10 == 6)
        printf("20");
    if (num % 10 == 7)
        printf("21");
    if (num % 10 == 8)
        printf("22");
    if (num % 10 == 9)
        printf("30");
}

void printnum7(int num) {
    if (num / 10)
        printnum7(num / 10);

    if (num % 10 == 0)
        printf("00");
    if (num % 10 == 1)
        printf("01");
    if (num % 10 == 2)
        printf("02");
    if (num % 10 == 3)
        printf("03");
    if (num % 10 == 4)
        printf("04");
    if (num % 10 == 5)
        printf("05");
    if (num % 10 == 6)
        printf("06");
    if (num % 10 == 7)
        printf("07");
    if (num % 10 == 8)
        printf("10");
    if (num % 10 == 9)
        printf("11");
}
