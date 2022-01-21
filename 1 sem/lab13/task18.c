#include <stdio.h>

int isspace(char sym);
char tolower(char sym);
int issog(char sym);
int isalpha (char sym);

typedef enum _State {
    S01, S02
} state;

int main(void)
{   
    int bl = 0, check = 0;
    char symbol, tmpalpha;
    long long set, tmp, set1, set2;
    state action = S01;

    while ((symbol = getchar()) != EOF) {
        switch(action) {
            case S01:
                tmp = 1;
                set = 0;

                if (isspace(symbol))
                    action = S01;

                if (isalpha(symbol)) {
                    tmpalpha = tolower(symbol);
                    if (issog(tmpalpha)) {
                        tmp <<= tmpalpha - 'a';
                        set += tmp;
                    }
                    action = S02;
                }
                break;
            case S02:
                if (isalpha(symbol)) {
                    tmpalpha = tolower(symbol);
                    if (issog(tmpalpha)) {
                        tmp = 1;
                        tmp <<= tmpalpha - 'a';
                        set += tmp;
                    }
                } else if (isspace(symbol) && !bl) {
                    action = S01;
                    set1 = set;
                    bl = 1;
                } else if (isspace(symbol) && bl) {
                    set2 = set;
                    if (!(set1 & set2))
                        check = 1;
                    set1 = set2;
                    action = S01;
                } else {
                    if (bl) {
                        if (!(set1 & set2))
                            check = 1;
                        set1 = set2;
                        action = S01;
                    } else
                        action = S01;
                }
                break;
        }       
    }

    if (check)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

int isspace(char sym) {
    return (sym == '\n' || sym == ' ' || sym == '\t' || sym == ',') ? 1 : 0;
}

char tolower(char sym) {
    return (sym <= 'Z') ? (sym + 32) : sym;    
}

int issog(char sym) {
    return (sym == 'a' || sym == 'e' || sym == 'u' || sym == 'i' || sym == 'o') ? 0 : 1;
}

int isalpha (char sym) {
    return ((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) ? 1 : 0;
}