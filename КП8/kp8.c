#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iterator.h"


int main(void)
{
    list* li = NULL;
    list_node* node = NULL;
    char string[10]; int sym = 0;
    iterator* it = NULL;
    
    li = create();
    it = created(li);

    while (strncmp(string, "0",2) != 0 && strncmp(string, "exit", 5) != 0) {
        it = created(li);
        node = iteratorGet(it);
        print(li);
        scanf("%s", string);
        if (strncmp(string, "1",2) == 0 || strncmp(string, "add", 4) == 0) {
            scanf("%d", &sym);
            add(li, node, sym);
        }
        printf("%s\n", string);
    }



}