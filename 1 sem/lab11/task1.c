#include <stdio.h>

typedef enum _State {
        S01, S02, S03, S04
} State;


int main(void)
{
    char sym;
    State num = S01;

    while ((sym = getchar()) != EOF) {
        switch (num) {
            case S01:
                if (sym = '/')
                    num = S02;
                break;
            case S02:
                if (sym = '/')
                    num = S03;
                else num = S01;
                break;
            case S03:
                
                break;

        }
    }



    return 0;
}