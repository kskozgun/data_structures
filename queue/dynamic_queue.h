#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief Node structure for the queue
 */
typedef struct queue_node_t{
    uint32_t data;
    struct queue_node_t *next;
} queue_node_t;


/**
 * @brief Queue structure
 */
typedef struct {
    queue_node_t *front;
    queue_node_t *rear;
    uint32_t size;
} queue_t;


/**
 * @brief Create a qeueue
 * @return pointer to the created queue
 */
queue_t *d_queue_create(void);


/**
 * @brief Get the size of the queue
 * @param q pointer to the queue
 * @return size of the queue
 */
uint32_t d_queue_size(queue_t *q);


/**
 * @brief Check if the queue is empty
 * @param q pointer to the queue
 * @return true if the queue is empty, false otherwise
 */
bool d_queue_is_empty(queue_t *q);


/**
 * @brief Add an element to the end of the queue
 * @param q pointer to the queue
 * @param value value to be added
 * @return true if the operation was successful, false otherwise
 */
bool d_queue_enqueue(queue_t *q, uint32_t value);


/**
 * @brief Remove an element from the front of the queue
 * @param q pointer to the queue
 * @param value pointer to store the removed value
 * @return true if the operation was successful, false otherwise
 */
bool d_queue_dequeue(queue_t *q, uint32_t *value);


/** 
 * @brief Get the value at the front of the queue without removing it
 * @param q pointer to the queue
 * @param value pointer to store the front value
 * @return true if the operation was successful, false otherwise
*/
bool d_queue_front(queue_t *q, uint32_t *value);


#endif // DYNAMIC_QUEUE_H