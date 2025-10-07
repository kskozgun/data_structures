#include <stdlib.h>
#include "static_queue.h"

void s_queue_init(s_queue_t *q)
{
    ASSERT(q);

    q->size = 0;
    q->rear = 0;
    q->front = 0;
}

uint32_t s_queue_size(s_queue_t *q)
{
    ASSERT(q);

    return q->size;
}

bool s_queue_is_empty(s_queue_t *q)
{
    ASSERT(q);

    return (q->size == 0);
}

bool s_queue_enqueue(s_queue_t *q, uint32_t val)
{
    ASSERT(q);

    if(q->size >= S_QUEUE_CAPACITY) {
        return false;
    }

    q->data[q->rear] = val;
    q->rear++;
    q->rear = (q->rear) % S_QUEUE_CAPACITY;
    q->size++;

    return true;
}

bool s_queue_dequeue(s_queue_t *q, uint32_t *val)
{
    ASSERT(q && val);

    if((q->size == 0)) {
        return false;
    }

    *val = q->data[q->front];
    q->front++;
    q->front = (q->front) % S_QUEUE_CAPACITY;
    q->size--;

    return true;
}

bool s_queue_front(s_queue_t *q, uint32_t *val)
{
    ASSERT(q && val);

    if((q->size == 0)) {
        return false;
    }

    *val = q->data[q->front];
    return true;
}