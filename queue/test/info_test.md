# Test Cases

The following test-cases are performed to ensure the correct setup and functionality of the `static_queue` module using Ceedling.

## 1. Initialization Tests

### `test_s_queue_init_should_initialize_empty_queue`
- Verify `s_queue_init()` sets size=0, front=0, rear=0

## 2. Size Tests

### `test_s_queue_size_should_return_zero_for_empty_queue`
- Verify `s_queue_size()` returns 0 for empty queue

### `test_s_queue_size_should_return_correct_count_after_enqueue`
- Enqueue 3 elements, verify size returns 3

## 3. Empty Check Tests

### `test_s_queue_is_empty_should_return_true_for_new_queue`
- Verify `s_queue_is_empty()` returns true for initialized queue

### `test_s_queue_is_empty_should_return_false_after_enqueue`
- Enqueue one element, verify returns false

## 4. Enqueue Tests

### `test_s_queue_enqueue_should_add_single_element`
- Enqueue value 42, verify returns true and size=1

### `test_s_queue_enqueue_should_fail_when_full`
- Fill queue to capacity, verify next enqueue returns false

## 5. Dequeue Tests

### `test_s_queue_dequeue_should_fail_on_empty_queue`
- Verify dequeue returns false on empty queue

### `test_s_queue_dequeue_should_return_fifo_order`
- Enqueue 10,20,30 then dequeue, verify returns 10,20,30 in order

### `test_s_queue_dequeue_should_update_size`
- Enqueue 2 elements, dequeue 1, verify size=1

## 6. Front Tests

### `test_s_queue_front_should_fail_on_empty_queue`
- Verify front returns false on empty queue

### `test_s_queue_front_should_return_first_element_without_removing`
- Enqueue 42,24, call front twice, verify both return 42 and size unchanged