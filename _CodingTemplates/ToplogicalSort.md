# Toplogical Sort

```js
function topologicalSort(numNodes, edges) {
  const graph = new Map(); // node -> neighbors
  const indegree = new Array(numNodes).fill(0);

  for (const [u, v] of edges) {
    if (!graph.has(u)) graph.set(u, []);
    graph.get(u).push(v);
    indegree[v]++;
  }

  const queue = [];
  for (let i = 0; i < numNodes; i++) {
    if (indegree[i] === 0) queue.push(i); // 从"没前置" 的开始
  }

  const order = [];
  while (queue.length > 0) {
    const node = queue.shift();
    order.push(node);
    for (const next of graph.get(node) || []) {
      if (--indegree[next] === 0) queue.push(next); // 前置清零就入队
    }
  }

  return order.length === numNodes ? order : []; // 不够长 = 有环
}
```

## Template

## Complexity

## Sample
