# Queue Data Structure

Queue is a linear data structure that follows the First In First Out (FIFO) principle. This means that the element that is added first to the queue will be the first one to be read/removed. 

It is used in various applications such as task scheduling, handling requests in web servers, and breadth-first search algorithms.

## Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| Enqueue   | Add an element to the end of the queue | O(1) |
| Dequeue   | Remove an element from the front of the queue | O(1) |
| Front      | Get the front element without removing it | O(1) |
| IsEmpty   | Check if the queue is empty | O(1) |
| Size      | Get the number of elements in the queue | O(1) |

## Implementations

In C, two implementation methods are commonly used for queues:

1. **Array-based Implementation**: This method uses a fixed-size array to store the elements of the queue. It is simple to implement but has a limitation on the maximum size of the queue. Since increase size of array and copying elements is costly, a circular array approach is often used to optimize space.

2. **Linked List-based Implementation**: This method uses a linked list to store the elements of the queue. It allows for dynamic sizing and can grow or shrink as needed, but it requires more memory overhead due to storing pointers.






