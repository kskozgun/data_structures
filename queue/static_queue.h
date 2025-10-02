#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdint.h>
#include <stdbool.h>

#define S_QUEUE_CAPACITY 100

typedef struct {
    uint32_t data[S_QUEUE_CAPACITY];
    uint32_t front;
    uint32_t rear;
    uint32_t size;
} s_queue_t;

void s_queue_init(s_queue_t *q);

bool s_queue_is_empty(s_queue_t *q);

uint32_t s_qeueu_size(s_queue_t *q);

bool s_qeueu_enqueue(s_queue_t *q, uint32_t value);

bool s_qeueu_deqeueu(s_queue_t *q, uint32_t *value);

bool s_qeueu_front(s_queue_t *q, uint32_t *value);

#endif // STATIC_QUEUE_H