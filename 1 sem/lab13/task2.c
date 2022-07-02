#include <stdio.h>

int tolower(char x);
int isspace(char x);
int isdigit(char x);
int isalpha(char x);
int isvowel(char x);

typedef enum _State {
    S01, S02, S03, S04
} state;

int main(void)
{
    char sym;
    int set = 0, tmp = 0, bl = 0;
    state action = S01;

    while ((sym = getchar()) != EOF) {
        switch(action) {
            case S01:
                set = 0;
                if (isdigit(sym))
                    action = S01;
                if (isspace(sym))
                    action = S01;
                if (isalpha(sym)) {
                    tmp = 1;
                    if (!isvowel(tolower(sym))) {
                        tmp = tmp << (tolower(sym) - 'a');
                        set += tmp;
                        bl = 1;
                    }
                    action = S02;
                }
                break;
            case S02:
                if (isdigit(sym))
                    action = S02;
                if (isspace(sym)) {
                    action = S01;
                    if (bl)
                        action = S04;
                }
                if (isalpha(sym)) {
                    tmp = 1;
                    if (!isvowel(tolower(sym))) {
                        tmp = tmp << (tolower(sym) - 'a');
                        action = S02;
                        if (!(tmp & set))
                            bl = 1;
                        else {
                            bl = 0;
                            action = S03;
                        }
                    set += tmp;
                    }
                }
                break;
            case S03:
                if (isspace(sym))
                    action = S01;
                break;
            case S04:
                break;
        }
    }

    if (action == S04 || bl)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

int isspace(char x) {
    return (x == ' ' || x == '\n' || x == '\t' || x == ',') ? 1 : 0;
}

int isdigit(char x) {
    return (x >= '0' && x <= '9') ? 1 : 0;
}

int isalpha(char x) {
    return (x >= 'A' && x <= 'z') ? 1 : 0;
}

int tolower(char x) {
    return (x < 'a') ? (x + 26) : x;
}

int isvowel(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
        return 1;
    
    return 0;
}
