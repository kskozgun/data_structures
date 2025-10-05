#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Placeholder for ASSERT macro
 * 
 * @note In production code, replace this with actual assertion handling.
 */
#define ASSERT(expr) ((void)0)

/**
 * @brief Node structure for the stack
 */
typedef struct stack_node_t {
    uint32_t data;
    struct stack_node_t *next;
} stack_node_t;


/**
 * @brief Stack structure
 */
typedef struct stack_t {
    stack_node_t *front;
    uint32_t size;
} stack_t;


/**
 * @brief Create a stack
 * @return pointer to the created stack
 */
stack_t *d_stack_create(void);

/**
 * @brief Get the size of the stack
 * @param s pointer to the stack
 * @return size of the stack
 */
uint32_t d_stack_size(stack_t *s);

/**
 * @brief Check if the stack is empty
 * @param s pointer to the stack
 * @return true if the stack is empty, false otherwise
 */
bool d_stack_is_empty(stack_t *s);

/**
 * @brief Remove the top element from the stack and store its value
 * @param s pointer to the stack
 * @param value pointer to store the removed value
 * @return true if the operation was successful, false otherwise
 */
bool d_stack_pop(stack_t *s, uint32_t *value);

/**
 * @brief Get the value of the top element without removing it
 * @param s pointer to the stack
 * @param value pointer to store the top value
 * @return true if the operation was successful, false otherwise
 */
bool d_stack_peek(stack_t *s, uint32_t *value);

/**
 * @brief Add an element to the top of the stack
 * @param s pointer to the stack
 * @param value value to be added
 * @return true if the operation was successful, false otherwise
 */
bool d_stack_push(stack_t *s, uint32_t value);

#endif // DYNAMIC_STACK_H