#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typescode.h"

tree *new_tree = NULL;

int main(void)  {
    char string[10];
    int value = 0;
    int parent = 0;
    tree *point = NULL;

    while (strncmp(string, "0",1) != 0 && strncmp(string, "exit", 4) != 0) {
        printf("1 - create\n2 - add\n3 - remove\n4 - print\n5 - function\n0 - exit\n");
        scanf("%s", string);
        if (strncmp(string, "1",1) == 0 || strncmp(string, "create", 6) == 0) {
            printf("name /\n");
            scanf("%d",&value);
            new_tree = create_tree(value);
        }
        if (strncmp(string, "2",1) == 0 || strncmp(string, "add", 3) == 0) {
            printf("parent & name : \n");
            scanf("%d", &parent);
            scanf("%d",&value);
            point = found_parent(new_tree,parent,value);
            if (point == NULL) {
                printf("not found parent!\n");
            } else {
                add_tree(point, value);
            }       
        }
        if (strncmp(string, "3",1) == 0 || strncmp(string, "remove", 6) == 0) {
            scanf("%d", &value);
            point = found(new_tree, value);
            if (point != NULL) {
                destroy(new_tree, value);
            } else {
                printf("Not found this!\n");
            }
        }
        if (strncmp(string, "4",1) == 0 || strncmp(string, "print",5 ) == 0) {
            print_Tree(new_tree,0);
        }
        if (strncmp(string, "5",1) == 0 || strncmp(string, "function", 8) == 0) {
            printf("count: %d\n",  counter(new_tree));
        }
        if (strncmp(string, "\0",1) == 0) {
        printf("fail.\n");
        break;
        }
    }
    printf("exiting...\n");
}
