# DFS

Backtracking 就是带 undo 的 DFS。

## Template

递归版

```js
function dfs(node, visited = new Set()) {
  if (!node || visited.has(node)) return;
  visited.add(node);
  // process(node)

  for (const neighbor of getNeighbors(node)) {
    dfs(neighbor, visited);
  }
}
```

迭代版（BFS 模板把 queue 换成 stack 就行）：

```js
function dfsIterative(start) {
  const visited = new Set([start]);
  const stack = [start];

  while (stack.length > 0) {
    const node = stack.pop(); // 唯一区别：pop 不是 shift
    // process(node)
    for (const neighbor of getNeighbors(node)) {
      if (!visited.has(neighbor)) {
        visited.add(neighbor);
        stack.push(neighbor);
      }
    }
  }
}
```

## Complexity

Time: O(V + E) — 跟 BFS 一样，每个顶点访问一次，每条边检查一次
Space: O(d) — d 是最大深度（递归栈）。最坏情况退化成链就是 O(V)。visited 另算 O(V)

## Sample
