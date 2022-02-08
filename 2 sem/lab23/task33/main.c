#include "function.h"
#include <string.h>

#define MAX 20
static void clear();

int main(void)
{
    node* tree = NULL;
    node* tmp = NULL;
    char command[MAX];
    int value;
    
    printf(" 1) add\n 2) remove\n 3) print\n 4) func\n 5) destroy\n");
    scanf("%s", command);
    while (strncmp(command, "exit", 5) && strncmp(command, "0", 2)) {
        if (!strncmp(command, "1", 2) || !strncmp(command, "add", 4)) {
            scanf("%d", &value);
            if (!tree){
                tree = CreateTree(value);
                printf("Start Tree with %d element\n", tree->key);
            } else {
                tmp = InsertTree(tree, value);
                printf("Add in Tree %d element\n", tmp->key);
            }
        } else if (!strncmp(command, "2", 2) || !strncmp(command, "remove", 7)) {
            scanf("%d", &value);
            DeleteNode(tree, value);
        } else if (!strncmp(command, "3", 2) || !strncmp(command, "print", 6))
            PrintTree(tree, 0);
        else if (!strncmp(command, "4", 2) || !strncmp(command, "func", 5))
            AmountVertex(tree);
        else if (!strncmp(command, "5", 2) || !strncmp(command, "destroy", 8))
            DestroyTree(tree);
        else
            printf("Incorrected format\n");
        
        clear();
        PrintTree(tree, 0);
        printf(" 1) add\n 2) remove\n 3) print\n 4) func\n 5) destroy\n");
        scanf("%s", command);
    }

    DestroyTree(tree);

    return 0;
}

static void clear() {
    char c;
    
    c = getchar();
    while (c != '\n' && c != '\0')
        c = getchar();
}