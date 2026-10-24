# BFS

## Time Complexity of BFS

For a graph with:
V = number of vertices (nodes)
E = number of edges

Time Complexity = O(V + E)

Each node is visited once
Each edge is checked once (in an adjacency list representation)

## Space Complexity of BFS

Space Complexity =O(V)

A queue is used to track nodes to visit → can store up to V nodes in the worst case
A visited set or array is used → stores up to V values

If the graph is dense, E could be up to V^2, so worst case: O(V^2)
If you're using an adjacency matrix, time becomes O(V²) because you check all possible edges
