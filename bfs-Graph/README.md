# Breadth-First Search with Graph

## Where BFS Is Used

- Finding the shortest path in an unweighted graph
- Solving puzzles (like sliding puzzles, mazes)
- Checking if a graph is bipartite
- Network analysis (e.g., finding degrees of separation)
- Checking if a graph is connected

## Complexity

## Template

```py
BFS(start):
    create a queue Q
    mark start as visited and enqueue it

    while Q is not empty:
        node = dequeue Q
        for each neighbor of node:
            if neighbor not visited:
                mark visited
                enqueue neighbor
```

```js
function bfs(root) {
  let queue = [root];
  let visited = new Set([root]);

  while (queue.length > 0) {
    const node = queue.shift();

    for (const neighbor of get_neighbors(node)) {
      if (visited.has(neighbor)) continue;
      queue.push(neighbor);
      visited.add(neighbor);
    }
  }
}
```
