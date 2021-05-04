#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iterator.h"


int main(void)
{
    list* li = NULL;
    list_node* node = NULL;
    char string[10]; char sym = 0;
    iterator* it = NULL;
    iterator* tmp = NULL;
    
    li = create();
    it = created(li);

    while (strncmp(string, "0",2) != 0 && strncmp(string, "exit", 5) != 0) {
        if (node) {
            it = update(node);
            printf("\n=========================\ncounts:%d\n", iterator_count(li));
        }
        print(li);

        if (node)
            iterator_print(it, li);
        scanf("%s", string);
        if (strncmp(string, "1",2) == 0 || strncmp(string, "add", 4) == 0) {

            scanf("\n%c", &sym);
            add(li, node, sym);
            if (!node)
                it = created(li);

        } else if ((strncmp(string, "right",6) == 0 || strncmp(string, "2", 2) == 0) && node)
            iterator_next(it);
        else if ((strncmp(string, "left",5) == 0 || strncmp(string, "3", 2) == 0) && node)
            iterator_back(it);
        else if (strncmp(string, "delete",7) == 0 || strncmp(string, "4", 2) == 0) {
            if (node) {
                if (node->prev) {
                    tmp = it;
                    iterator_back(tmp);
                    iteratorSet(iteratorGet(tmp),it);
                }
                else if (node->next) {
                    tmp = it;
                    iterator_next_NULL(tmp);
                    iteratorSet(iteratorGet(tmp),it);
                } else if (node->next == NULL && node->prev == NULL)
                    iteratorSet(NULL,it);
            
                delete(li, node);
            } else printf("Not dound list, whitch can delete!\n");

        } else if ((strncmp(string, "function",7) == 0 || strncmp(string, "5", 2) == 0) && node) {
                scanf("\n%c", &sym);
                if (foo(li, sym)) {
                    iteratorSet(li->head, it);
                    delete(li, iteratorGet(it));
                    iteratorSet(NULL,it);
                }
        }

        node = iteratorGet(it);

    }



}