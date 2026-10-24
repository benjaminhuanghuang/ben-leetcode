# Graphs P247

A graph is a data structure made up of nodes (called vertices) that are connected by edges. Graphs are used to model relationships, with the edges representing the connections between the vertices.

```js

```

Terminology:

- Adjacent node/neighbor: two nodes are adjacent if there's an edge connecting them.
- Degree: the number of edges connected to a node.
- Path : a sequence of nodes connected by edges.
- DAG: directed acyclic graph

Attributes:

- Directed vs. undirected: in a directed graph, edges have a direction associated with them.
- Weighted vs. unweighted: in a weighted graph, edges have a weight associated with them, such as distance or cost.
- Cyclic vs. acyclic: A cyclic graph contains at least one cycle, which is a path that starts and ends at the same node.

Representations:

- In an adjacency list, the neighbors of each node are stored as a list. Adjacency lists can be implemented
  using a hash map, where the key represents the node, and Its corresponding value represents the list of that node's neighbors.

- In an adjacency matrix, the graph is represented as a 20 matrix where matrix[i][j] indicates an
  edge between nodes i and j

## Traversal

```py
def dfs(node: GraphNode, visited: Set[GraphNode]):
    visited.add(node)
    process(node)

    for neighbor in node.neighbors:
        if neighbor not in visited:
            dfs(neighbor, visited)
```

```py
def bfs(node: GraphNode):
    visited = set()
    queue = deque([node])

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            process(node)
            for neighbor in node.neighbors:
                queue.append(neighbor)
```

Both OFS and BFS have a time complexity of O(n + e)
n denotes the number of nodes and
e denotes the number of edges.

This is because during traversal, each node is visited once, and each
edge is explored once. They both also share a space complexity of O(n). For DFS, this is due to the
space taken up by the recursive call stack, and for BFS, it's due to the space taken up by the queue.

They both also share a space complexity of O(n).
For DFS In the worst case, the DFS goes as deep as all the vertices (for example, in a path-shaped graph)
The recursion (or stack) will then hold up to n vertices. That is O(n) space, the other O(n) space for the visited node.

BFS it's due to the space taken up by the queue and the space for the visited node.

## Union-Find

This is where the Union-Find data structure, also known as the Disjoint Set Union (DSU) data structure,
comes in.

Union-Find consists of two operations:

- Union: takes two elements from different sets and makes them part of the same set
- Find: determines what set an element belongs to.
