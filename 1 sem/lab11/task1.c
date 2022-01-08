#include <stdio.h>

int isspace(char c);
int isnext(char c);

typedef enum _State {
        S01, S02, S03, S04, S05
} State;

int main(void)
{
    int count = 0;
    char sym;
    State num = S01;

    while ((sym = getchar()) != EOF) {
        switch (num) {
            case S01:
                if (sym == '/')
                    num = S02;
                break;
            case S02:
                if (sym == '/')
                    num = S03;
                else num = S01;
                break;
            case S03:
                if (isnext(sym))
                    num = S01;
                else if (isspace(sym))
                    num = S04;
                else num = S05;
                break;
            case S04:
                if (isnext(sym))
                    num = S01;
                else if (isspace(sym))
                    continue;
                else num = S05; 
                break;
            case S05:
                if (isnext(sym)) {
                    num = S01;
                    count++;
                }
                if (isspace(sym)) {
                    count++;
                    num = S03;
                }
                break;
        }
    }

    if (num == S05)
        count++;

    printf("words = %d\n", count);

    return 0;
}

int isspace(char c) {
    if (c == ' ' || c == '\t' || c == ',')
        return 1;

    return 0;
}

int isnext(char c) {
    if (c == '\n' || c == '\0')
        return 1;

    return 0;
}