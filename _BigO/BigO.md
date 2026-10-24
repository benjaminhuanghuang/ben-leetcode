# Big O notation

Big O notation is a way to describe how the performance (time or space) of an algorithm grows relative to the size of its input

## Common Big O Complexities (Time or Space)

| Big O      | Name             | Example                          | Description                          |
| ---------- | ---------------- | -------------------------------- | ------------------------------------ |
| O(1)       | Constant time    | Accessing array element          | Doesn't grow with input size         |
| O(log n)   | Logarithmic time | Binary search                    | Input size shrinks by half each step |
| O(n)       | Linear time      | Loop through array               | Grows proportionally with input      |
| O(n log n) | Log-linear time  | Merge sort, quicksort (avg)      | Efficient sorting                    |
| O(n^2)     | Quadratic time   | Nested loops (e.g., bubble sort) | Gets slow quickly                    |
| O(2^N)     | Exponential time | Recursive Fibonacci              | Grows very fast                      |
| O(n!)      | Factorial time   | Solving permutations             | Extremely inefficient                |

## Reference

<https://www.freecodecamp.org/news/learn-big-o-notation/>
