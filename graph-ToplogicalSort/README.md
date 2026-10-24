# Topological Sort

DFS, add the node the visited array befr popping the stack.
If a node is already added to visited, there is a cycle.
Answer is the reverse of the visited array.

## When to use

## Complexity

Time Complexity: DFS O(V + E)
Space Complexity:

## Template

```js
for each node:
    if not marked:
        if (dfs(node) == CYCLE) return CYCLE
    return OK

dfs(node) :
    if node is marked as visited: return OK
    if node is marked as visiting: return CYCLE
    mark node as visiting
    for each new_node in node.neight
        if dfs (new_node) == CYCLE: return CYCLE
    mark node as visited
    add node to the head of orderd-list, sort the nodes
return OK
```

```js
function findInDegree(graph) {
  const inDegree = new Map();
  for (let node of graph.keys()) {
    inDegree.set(node, 0);
  }
  for (let node of graph.keys()) {
    for (neighbor of graph.get(node)) {
      inDegree.set(node, neighbor.get(node) + 1);
    }
  }
  return inDegree;
}
// BSF
function topoSort(graph) {
  const res = [];
  const q = [];
  const inDegree = findInDegree(graph);
  for (let node of inDegree.keys()) {
    if (inDegree.get(node) == 0) {
      q.push(node);
    }
  }
  while (q.length > 0) {
    const node = q.shift();
    res.push(node);
    for (let neighbor of graph.get(node)) {
      inDegree.set(neighbor, inDegree.get(neighbor) - 1);
      if (inDegree.get(neighbor) == 0) {
        q.push(neighbor);
      }
    }
  }
  return graph.size === res.length ? res : null;
}
```

## Reference

- 花花酱 LeetCode 210. Course Schedule II - 刷题找工作 EP133
  <https://www.youtube.com/watch?v=Qqgck2ijUjU>

---

## (merged from _CodingTemplates/ToplogicalSort.md)

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
