#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include <sys/types.h>
#include <unistd.h>


#define MAX 255

char*       gets_s(void);
char*       WorkAppProc(char* name, char* string);
static int  IsVowel(char c);

int main(void) {
    pid_t pid1 = 0;
    int pipefd1[2], pipefd2[2];
    char* str = NULL;
    int length = 0;

    if (pipe(pipefd1) < 0 || pipe(pipefd2) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1) {
        pid_t pid2 = fork();
        if (pid2 == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid2) {              // parent
            close(pipefd1[0]);
            close(pipefd2[0]);

            printf("Enter name file for child1:\n > ");
            str = gets_s();
            length = strlen(str) + 1;
            write(pipefd1[1], &length, sizeof(int));
            write(pipefd1[1], str, strlen(str) + 1);
            free(str);

            printf("Enter name file for child2:\n > ");
            str = gets_s();
            length = strlen(str) + 1;
            write(pipefd2[1], &length, sizeof(int));
            write(pipefd2[1], str, strlen(str) + 1);
            free(str);

            printf("Enter strings:\n");
            str = gets_s();
            while (str[0] != '\0') {
                srand(time(NULL));
                int rndm = rand() % 100;

                if (rndm >= 0 && rndm < 80) {
                    printf("messege for child1\n");
                    length = strlen(str) + 1;
                    write(pipefd1[1], &length, sizeof(int));
                    write(pipefd1[1], str, strlen(str) + 1);
                } else {
                    printf("messege for child2\n");
                    length = strlen(str) + 1;
                    write(pipefd2[1], &length, sizeof(int));
                    write(pipefd2[1], str, strlen(str) + 1);
                }

                free(str);
                str = gets_s();
            }

            length = 0;
            write(pipefd1[1], &length, sizeof(int));
            write(pipefd2[1], &length, sizeof(int));
            free(str);
        } else {                    // child proc 2
            close(pipefd2[1]);
            char* string;
            char* name;
            int bytes;
    
            read(pipefd2[0], &bytes, sizeof(int));
            name = (char *) malloc(sizeof(char) * bytes);
            read(pipefd2[0], name, sizeof(char) * bytes);

            while (1) {
                read(pipefd2[0], &bytes, sizeof(int));
                if (bytes == 0)
                    break;

                string = (char *) malloc(sizeof(char) * bytes);
                read(pipefd2[0], string, sizeof(char) * bytes);
                printf("child2 work\n");
                WorkAppProc(name, string);
                free(string);
            }

            free(name);
        }
    } else {                        // child proc 1
        close(pipefd1[1]);
        char* string;
        char* name;
        int bytes;
 
        read(pipefd1[0], &bytes, sizeof(int));
        name = (char *) malloc(sizeof(char) * bytes);
        read(pipefd1[0], name, sizeof(char) * bytes);

        while (1) {
            read(pipefd1[0], &bytes, sizeof(int));
            if (bytes == 0)
                break;

            string = (char *) malloc(sizeof(char) * bytes);
            read(pipefd1[0], string, sizeof(char) * bytes);
            printf("child1 work\n");
            WorkAppProc(name, string);
            free(string);
        }

        free(name);
    }


    return 0;
}

char* gets_s(void) {
    char* string = NULL;
    char* sym = NULL;
    int i = 0;
    
    string = (char *) malloc(sizeof(char) * MAX);
    while (sym == NULL) {
        string = fgets(&string[i * MAX], MAX, stdin);
        sym = strchr(string, '\n');
        ++i;

        if (!sym) {
            string = (char *) realloc(string, (i + 1) * MAX);
        }
    }

    *sym = '\0';
    return string;
}

char* WorkAppProc(char* name, char* string) {
    char* tmp = string;
    char sym;
    FILE* file = fopen(name, "a+");

    while (*tmp != '\0') {
        if (IsVowel(*tmp)) {
            ++tmp;
            continue;
        }

        fwrite(tmp, sizeof(char), 1, file);
        ++tmp;
    }

    sym = '\n';
    fwrite(&sym, sizeof(char), 1, file);
    fclose(file);
}

static int IsVowel(char c) {
    c = tolower(c);

    if (c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'a') {
        return 1;
    }

    return 0;
}