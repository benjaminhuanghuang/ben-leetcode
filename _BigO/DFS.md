# DFS

## Time Complexity of DFS

For a graph with:
V = number of vertices (nodes)
E = number of edges

Time Complexity: O(V + E)

Why?
Every vertex is visited once
Every edge is explored once

This holds true for both recursive and iterative DFS (using a stack)

## Space Complexity of DFS

Space Complexity: = O(V) in the best case

Up to O(H), where H is the maximum depth of the recursion stack or call stack in recursive DFS

### Iterative DFS

Uses an explicit stack

Space: O(V) (for the stack and visited set)

### Recursive DFS

Uses the call stack

In worst case (deep tree or graph), stack can grow up to O(V)
