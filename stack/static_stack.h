#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdint.h>
#include <stdbool.h>

#define S_STACK_CAPACITY 100

#define ASSERT(expr) ((void)0)

typedef struct {
    uint32_t data[S_STACK_CAPACITY];
    uint32_t front;
    uint32_t size;
} stack_t;

/**
 * @brief Initialize the stack
 * @param s pointer to the stack
 * @return void
 */
void s_stack_init(stack_t *s);

/**
 * @brief Get the size of the stack
 * @param s pointer to the stack
 * @return size of the stack
 */
uint32_t s_stack_size(stack_t *s);

/**
 * @brief Check if the stack is empty
 * @param s pointer to the stack
 * @return true if the stack is empty, false otherwise
 */
bool s_stack_is_empty(stack_t *s);

/**
 * @brief Add an element to the top of the stack
 * @param s pointer to the stack
 * @param value value to be added
 * @return true if the operation was successful, false otherwise
 */
bool s_stack_push(stack_t *s, uint32_t value);

/**
 * @brief Remove the top element from the stack and store its value
 * @param s pointer to the stack
 * @param value pointer to store the removed value
 * @return true if the operation was successful, false otherwise
 */
bool s_stack_pop(stack_t *s, uint32_t *value);

/**
 * @brief Get the value of the top element without removing it
 * @param s pointer to the stack
 * @param value pointer to store the top value
 * @return true if the operation was successful, false otherwise
 */
bool s_stack_peek(stack_t *s, uint32_t *value);

#endif // STATIC_STACK_H