# Depth-First Search with Graph

## When to use

## Template

```js
function dfs(root, visited) {
  for (const neighbor of get_neighbors(root)) {
    if (visited.has(neighbor)) continue;
    visited.add(neighbor);
    dfs(neighbor, visited);
  }
}
```
