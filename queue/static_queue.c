#include <stdlib.h>
#include "static_queue.h"

void s_queue_init(s_queue_t *q)
{
    q->size = 0;
    q->rear = 0;
    q->front = 0;
}

uint32_t s_qeueu_size(s_queue_t *q)
{
    if(q == NULL) {
        return 0U;
    }
    return q->size;
}

bool s_queue_is_empty(s_queue_t *q)
{
    if(q == NULL) {
        return true;
    }

    if(q->size == 0) {
        return true;
    }
    return false;
}

bool s_queue_enqeue(s_queue_t *q, uint32_t val)
{
    if(q == NULL && q->size >= S_QUEUE_CAPACITY) {
        return false;
    }

    q->rear++;
    q->rear = (q->rear) % S_QUEUE_CAPACITY;
    q->data[q->rear] = val;
    q->size++;

    return true;
}

bool s_queue_dequeue(s_queue_t *q, uint32_t *val)
{
    if((q == NULL) & (q->size == 0)) {
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
    if((q == NULL) & (q->size == 0)) {
        return false;
    }

    *val = q->data[q->front];
    return true;
}