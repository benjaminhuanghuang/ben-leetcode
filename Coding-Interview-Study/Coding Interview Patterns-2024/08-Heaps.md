# Heaps P143

A heap is a data structure that organizes elements based on priority, ensuring the highest-priority
element is always at the top of the heap.

Priority queue
A priority queue is a special type of heap that follows the structure of min-heaps or max-heaps but
allows customization in how elements are prioritized (e.g., prioritizing strings with a higher number
of vowels).

| Operation | Time complexity | Description                                                                                        |
| --------- | --------------- | -------------------------------------------------------------------------------------------------- |
| Insert    | O(log(n))       | Adds an element to the heap, ensuring the binary tree remains correctly ordered.                   |
| Deletion  | O(log(n))       | Removes the element at the top of the heap, then restructures the heap to replace the top element. |
| Peek      | O(1)            | Retrieves the top element of the heap without removing it.                                         |
| Heapify   | O(n)            | Transforms an unsorted list of values into a heap [1].                                             |
