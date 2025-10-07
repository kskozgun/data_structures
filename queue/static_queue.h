#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Placeholder for ASSERT macro
 * 
 * @note In production code, replace this with actual assertion handling.
 */
#define ASSERT(expr) ((void)0)

#define S_QUEUE_CAPACITY 100

/**
 * @brief Static queue structure
 * @note The capacity of the queue is fixed at S_QUEUE_CAPACITY
 */
typedef struct {
    uint32_t data[S_QUEUE_CAPACITY];
    uint32_t front;
    uint32_t rear;
    uint32_t size;
} s_queue_t;

/**
 * @brief Initialize the static queue
 * @param q pointer to the static queue
 * @return void
 */
void s_queue_init(s_queue_t *q);

/**
 * @brief Check if the static queue is empty
 * @param q pointer to the static queue
 * @return true if the queue is empty, false otherwise
 */
bool s_queue_is_empty(s_queue_t *q);

/**
 * @brief Get the size of the static queue
 * @param q pointer to the static queue
 * @return size of the queue
 */
uint32_t s_queue_size(s_queue_t *q);

/**
 * @brief Add an element to the end of the static queue
 * @param q pointer to the static queue
 * @param value value to be added
 * @return true if the operation is successful, false otherwise
 */
bool s_qeueu_enqueue(s_queue_t *q, uint32_t value);

/**
 * @brief Remove an element from the front of the static queue
 * @param q pointer to the static queue
 * @param value pointer to store the removed value
 * @return true if the operation is successful, false otherwise
 */
bool s_queue_dequeue(s_queue_t *q, uint32_t *value);

/**
 * @brief Get the front element of the static queue without removing it
 * @param q pointer to the static queue
 * @param value pointer to store the front value
 * @return true if the operation is successful, false otherwise
 */
bool s_queue_front(s_queue_t *q, uint32_t *value);

#endif // STATIC_QUEUE_H