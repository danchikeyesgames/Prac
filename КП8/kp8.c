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
        if (node)
            it = update(node);
        print(li);
        if (node)
            iterator_print(it, li);
        scanf("%s", string);
        if (strncmp(string, "1",2) == 0 || strncmp(string, "add", 4) == 0) {
            
            scanf("%d", &sym);
            add(li, node, sym);
            if (!node)
                it = created(li);

        } else if (strncmp(string, "right",6) == 0 || strncmp(string, "2", 2) == 0)
            iterator_next(it);
        else if (strncmp(string, "left",5) == 0 || strncmp(string, "3", 2) == 0)
            iterator_back(it);
        
        node = iteratorGet(it);
        
    }



}