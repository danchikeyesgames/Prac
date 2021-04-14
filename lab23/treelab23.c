#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typescode.h"

tree *new_tree = NULL;

int main(void)  {
    char string[10];
    int value = 0;
    tree *point = NULL;
    printf("1 - add\n2 - remove\n3 - print\n4 - function\n0 - exit\n");
    while (strncmp(string, "0",2) != 0 && strncmp(string, "exit", 4) != 0) {
        scanf("%s", string);
        if (strncmp(string, "1",2) == 0 || strncmp(string, "add", 3) == 0) {
            printf("name : ");
            scanf("%d",&value);
            printf("%d add\n", value);
            if (new_tree == NULL) {
                new_tree = create_tree(value);
            } else {
                add_tree(new_tree, value); 
            }
        }
        if (strncmp(string, "2",2) == 0 || strncmp(string, "remove", 6) == 0) {
            scanf("%d", &value);
            point = found(new_tree, value);
            if (point != NULL) {
                new_tree = destroy(new_tree, value);
            } else {
                printf("Not found this!\n");
            }
        }
        if (strncmp(string, "3",2) == 0 || strncmp(string, "print",5 ) == 0) {
            print_Tree(new_tree,0);
        }
        if (strncmp(string, "4",2) == 0 || strncmp(string, "function", 8) == 0) {
            printf("count: %d\n",  counter(new_tree));
        }
        print_Tree(new_tree,0);  
    }
    printf("exiting...\n");
}
