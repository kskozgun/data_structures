#include <stdlib.h>
#include "dynamic_stack.h"

stack_t *d_stack_create(void)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    if(stack == NULL) {
        return NULL;
    }

    stack->front = NULL;
    stack->size = 0U;

    return stack;
}

uint32_t d_stack_size(stack_t *s)
{
    ASSERT(s);

    return s->size;
}

bool d_stack_is_empty(stack_t *s)
{
    ASSERT(s);

    return (s->size == 0);
}

bool d_stack_push(stack_t *s, uint32_t value)
{
    ASSERT(s);

    stack_node_t *node = (stack_node_t *)malloc(sizeof(stack_node_t));
    if(node == NULL) {
        return false;
    }

    stack_node_t *temp_node = s->front;

    s->front = node;
    s->front->data = value;
    s->front->next = temp_node;
    s->size++;
    
    return true;
}

bool d_stack_pop(stack_t *s, uint32_t *value)
{
    ASSERT(s && value);

    if(d_stack_is_empty(s)) {
        return false;
    }

    stack_node_t *temp_node = s->front;
    *value = s->front->data;

    s->front = s->front->next;

    s->size--;
    free(temp_node);

    return true;
}

bool d_stack_peek(stack_t *s, uint32_t *value)
{
    ASSERT(s && value);

    if(d_stack_is_empty(s)) {
        return false;
    }

    *value = s->front->data;

    return true;
}

