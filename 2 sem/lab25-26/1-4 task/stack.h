#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>

typedef struct _Stack_int {
    unsigned int key;
    int value;
    struct _Stack_int* next;
} stack_node;

typedef struct _Stack_head {
    size_t size;
    stack_node* head;
} stack;

stack*          stack_create();
stack_node*     stack_node_create(unsigned int key, int value);
stack_node*     stack_pop(stack* head);
void            stack_push(stack* head, unsigned int key, int value);
void            stack_push_node(stack* head, stack_node* node);
size_t          stack_take_size(stack* head);
unsigned int    stack_take_key(stack_node* node);
int             stack_take_value(stack_node* node);
void            stack_clear(stack* head);
void            stack_destroy(stack* head);

#endif  // __STACK_H__  