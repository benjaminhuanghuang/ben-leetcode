# BFS

## Template

```js
function bfs(start) {
  const visited = new Set([start]);
  const queue = [start];

  while (queue.length > 0) {
    const node = queue.shift();
    // process(node)

    for (const neighbor of getNeighbors(node)) {
      if (!visited.has(neighbor)) {
        visited.add(neighbor);  // 入队时标记！
        queue.push(neighbor);
      }
    }
  }
}
```

```js
function levelOrder(root) {
  if (!root) return [];
  const result = [];
  const queue = [root];

  while (queue.length > 0) {
    const levelSize = queue.length; // 先记本层长度，队列会变长
    const level = [];
    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift();
      level.push(node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
    result.push(level);
  }
  return result;
}
```

## Complexity

Time: O(V + E) — 每个顶点出队一次，每条边检查一次。

二叉树就是 O(n)。n 个节点的树恰好有 n−1 条边，代入得 O(n + n−1) = O(n)。直观想：每个节点就看左、右两个孩子，常数工作量 × n 个节点。

Space: O(w) — w 是最大宽度，队列最多同时装一层。最坏 O(n)。

## Sample
