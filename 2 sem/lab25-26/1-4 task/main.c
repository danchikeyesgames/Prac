#include <stdio.h>

#include "stack.h"

void stack_bubblesort(stack* s);
void stack_procedure(stack* s);

int main(void) {
    unsigned int key = 0;
    int value = 0;
    size_t size = 0; 
    stack* Stack = stack_create();
    stack_node* node = NULL;

    scanf("%d%d", &key, &value);
    while (key != 0 || value != 0) {
        stack_push(Stack, key, value);
        scanf("%d%d", &key, &value);
    }

    // stack_procedure(Stack);
    stack_bubblesort(Stack);

    size = stack_take_size(Stack);
    for (int i = 0; i < size; ++i) {
        node = stack_pop(Stack);
        value = stack_take_value(node);
        key = stack_take_key(node);
        free(node);
        node = NULL;

        printf("%u - %d\n", key, value);
    }

    stack_destroy(Stack);
    return 0;
}

void stack_bubblesort(stack* s) {
    size_t size = stack_take_size(s);
    for (int i = 1; i < size; ++i) {
        stack_procedure(s);
    }
}

void stack_procedure(stack* s) {
    stack_node* left_node   = NULL;
    stack_node* right_node  = NULL;
    stack*  new_stack = stack_create();
    
    size_t size = stack_take_size(s);
    left_node = stack_pop(s);
    for (int i = 1; i < size; ++i) {
        if (i != 1) left_node = right_node;
        right_node = stack_pop(s);

        if (stack_take_key(left_node) > stack_take_key(right_node)) {
            stack_push_node(new_stack, right_node);
            right_node = left_node;
        } else {
            stack_push_node(new_stack, left_node);
        }
    }
    stack_push_node(new_stack, right_node);

    for (int i = 0; i < size; ++i) {
        left_node = stack_pop(new_stack);
        stack_push_node(s, left_node);
    }

    stack_destroy(new_stack);
}