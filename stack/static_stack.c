#include "static_stack.h"

void s_stack_init(stack_t *s)
{
    ASSERT(s);

    s->front = 0;
    s->size = 0;
}

uint32_t s_stack_size(stack_t *s)
{
    ASSERT(s);

    return s->size;
}

bool s_stack_is_empty(stack_t *s)
{
    ASSERT(s);

    return (s->size == 0);
}

bool s_stack_push(stack_t *s, uint32_t value)
{
    ASSERT(s);
    if(s->size >= S_STACK_CAPACITY) {
        return false;
    }

    s->data[s->front] = value;
    s->front++;
    s->size++;

    return true;
}

bool s_stack_pop(stack_t *s, uint32_t *value)
{
    ASSERT(s && value);

    if(s_stack_is_empty(s)) {
        return false;
    }

    /* Front points to the next empty slot, not the top element. */
    *value = s->data[s->front - 1U]; 
    s->front--;
    s->size--;

    return true;
}

bool s_stack_peek(stack_t *s, uint32_t *value)
{
    ASSERT(s && value);

    if(s_stack_is_empty(s)) {
        return false;
    }

    /* Front points to the next empty slot, not the top element. */
    *value = s->data[s->front - 1U];

    return true;
}