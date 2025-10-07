#include "unity.h"
#include "static_queue.h"

// Test fixture - runs before each test
void setUp(void)
{
    // Setup code here if needed
}

// Test fixture - runs after each test
void tearDown(void)
{
    // Cleanup code here if needed
}

/* Initialization Tests */
void test_s_queue_init_should_initialize_empty_queue(void)
{
    s_queue_t queue = {
        .front = 0xFFFFFFFF,
        .rear = 0xFFFFFFFF,
        .size = 0xFFFFFFFF
    };
    
    s_queue_init(&queue);
    
    TEST_ASSERT_EQUAL_UINT32(0, queue.size);
    TEST_ASSERT_EQUAL_UINT32(0, queue.front);
    TEST_ASSERT_EQUAL_UINT32(0, queue.rear);
}

/* Size Tests*/
void test_s_queue_size_should_return_zero_for_empty_queue(void)
{
    s_queue_t queue = {
        .size = 0xFFFFFFFF
    };
    
    s_queue_init(&queue);
    
    uint32_t size = s_queue_size(&queue);
    
    TEST_ASSERT_EQUAL_UINT32(0, size);
}

void test_s_queue_size_should_return_correct_count_after_enqueue(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    
    s_queue_enqueue(&queue, 10);
    s_queue_enqueue(&queue, 20);
    s_queue_enqueue(&queue, 30);
    
    TEST_ASSERT_EQUAL_UINT32(3, s_queue_size(&queue));
}

/* Empty Check Tests */
void test_s_queue_is_empty_should_return_true_for_new_queue(void)
{
    s_queue_t queue = {
        .size = 0xFFFFFFFF
    };
    s_queue_init(&queue);
    
    TEST_ASSERT_TRUE(s_queue_is_empty(&queue));
}

void test_s_queue_is_empty_should_return_false_after_enqueue(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    
    s_queue_enqueue(&queue, 42);
    
    TEST_ASSERT_FALSE(s_queue_is_empty(&queue));
}

/* Enqueue Tests */
void test_s_queue_enqueue_should_add_single_element(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    
    bool result = s_queue_enqueue(&queue, 42);
    
    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_EQUAL_UINT32(1, s_queue_size(&queue));
}

void test_s_queue_enqueue_should_fail_when_full(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    
    // Fill queue to capacity
    for(int i = 0; i < S_QUEUE_CAPACITY; i++) {
        TEST_ASSERT_TRUE(s_queue_enqueue(&queue, i));
    }
    
    // Next enqueue should fail
    bool result = s_queue_enqueue(&queue, 999);
    TEST_ASSERT_FALSE(result);
}

/* Dequeue Tests */
void test_s_queue_dequeue_should_fail_on_empty_queue(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    uint32_t value;
    
    bool result = s_queue_dequeue(&queue, &value);
    
    TEST_ASSERT_FALSE(result);
}

void test_s_queue_dequeue_should_return_fifo_order(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    uint32_t value;
    
    // Enqueue in order: 10, 20, 30
    s_queue_enqueue(&queue, 10);
    s_queue_enqueue(&queue, 20);
    s_queue_enqueue(&queue, 30);
    
    // Dequeue should return in same order: 10, 20, 30 (FIFO)
    TEST_ASSERT_TRUE(s_queue_dequeue(&queue, &value));
    TEST_ASSERT_EQUAL_UINT32(10, value);
    
    TEST_ASSERT_TRUE(s_queue_dequeue(&queue, &value));
    TEST_ASSERT_EQUAL_UINT32(20, value);
    
    TEST_ASSERT_TRUE(s_queue_dequeue(&queue, &value));
    TEST_ASSERT_EQUAL_UINT32(30, value);
}

void test_s_queue_dequeue_should_update_size(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    uint32_t value;
    
    // Enqueue 2 elements
    s_queue_enqueue(&queue, 42);
    s_queue_enqueue(&queue, 24);
    TEST_ASSERT_EQUAL_UINT32(2, s_queue_size(&queue));
    
    // Dequeue 1 element
    s_queue_dequeue(&queue, &value);
    TEST_ASSERT_EQUAL_UINT32(1, s_queue_size(&queue));
}

/* Front Tests */
void test_s_queue_front_should_fail_on_empty_queue(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    uint32_t value;
    
    bool result = s_queue_front(&queue, &value);
    
    TEST_ASSERT_FALSE(result);
}

void test_s_queue_front_should_return_first_element_without_removing(void)
{
    s_queue_t queue;
    s_queue_init(&queue);
    uint32_t value;
    
    s_queue_enqueue(&queue, 42);
    s_queue_enqueue(&queue, 24);
    
    // First front call should return 42
    TEST_ASSERT_TRUE(s_queue_front(&queue, &value));
    TEST_ASSERT_EQUAL_UINT32(42, value);
    
    // Queue should be unchanged
    TEST_ASSERT_EQUAL_UINT32(2, s_queue_size(&queue));
    
    // Second front call should still return 42
    TEST_ASSERT_TRUE(s_queue_front(&queue, &value));
    TEST_ASSERT_EQUAL_UINT32(42, value);
    
    // Queue should still be unchanged
    TEST_ASSERT_EQUAL_UINT32(2, s_queue_size(&queue));
}
