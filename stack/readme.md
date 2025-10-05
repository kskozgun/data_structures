# Stack Data Structure

Stack is linear data structure that follows the Last In First Out (LIFO) principle. This means that the element that is added last to the stack will be the first one to be read/removed.

It is used in various applications such as expression evaluation, backtracking algorithms, and function call management in programming languages.

## Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| Push      | Add an element to the top of the stack | O(1) |
| Pop       | Remove an element from the top of the stack | O(1) |
| Peek      | Get the top element without removing it | O(1) |
| IsEmpty   | Check if the stack is empty | O(1) |
| Size      | Get the number of elements in the stack | O(1) |

## Implementations

In C, two implementation methods are commonly used for stacks:

1. **Array-based Implementation**: This method uses a fixed-size array to store the elements of the stack. It is simple to implement but has a limitation on the maximum size of the stack. Dynamic resizing can be implemented but may involve costly operations like copying elements.

2. **Linked List-based Implementation**: This method uses a linked list to store the elements of the stack. It allows for dynamic sizing and can grow or shrink as needed, but it requires more memory overhead due to storing pointers.
