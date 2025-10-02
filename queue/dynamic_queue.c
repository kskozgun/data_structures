#include "dynamic_queue.h"

queue_t *d_queue_create(void) {
    queue_t *q = malloc(sizeof(queue_t));

    if(q == NULL) {
        return NULL;
    }

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    return q;
}

bool d_queue_is_empty(queue_t *q) {
    if(q == NULL) {
        return false;
    }

    uint32_t size = q->size;

    if(size == 0) {
        return true;
    }
    return false;
}

uint32_t d_queue_size(queue_t *q)
{
    if(q == NULL) {
        return 0U;
    }
    uint32_t size = q->size;
    return size;
}


bool d_queue_enqueue(queue_t *q, uint32_t value) {
    if(q == NULL) {
        return false;
    }

    uint32_t is_empty = d_queue_is_empty(q);
    queue_node_t *new_node = (queue_node_t*)malloc(sizeof(queue_node_t));
    if(new_node == NULL) {
        return false;
    }

    new_node->data = value;
    new_node->next = NULL;

    if(is_empty) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;

    return true;
}

bool d_queue_front(queue_t *q, uint32_t *value) {
    if((q == NULL) || d_queue_is_empty(q)) {
        return NULL;
    }

    *value = q->front->data;

    return true;
}

bool d_queue_dequeue(queue_t *q, uint32_t *value) {
    if(q == NULL || d_queue_is_empty(q)) {
        return false;
    }

    /* Store the data */
    *value = q->front->data;

    queue_node_t *temp_node = q->front;

    q->front = q->front->next;

    if(q->front == NULL) {
        q->rear = NULL;
    }

    q->size--;
    free(temp_node);

    return true;
}