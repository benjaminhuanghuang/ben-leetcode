# Breadth-First Search with Matrix

## When to use

## Complexity

## Template

```js
function bfs(root) {
  let queue = [root];
  while (queue.length > 0) {
    const node = queue.shift();
    for (const child of node.children) {
      if (isGoal(child)) {
        return FOUND(child);
      }
      queue.push(child);
    }
  }
  return NOT_FOUND;
}
```
