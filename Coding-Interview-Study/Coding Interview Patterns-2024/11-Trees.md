# Trees P189

```js
function dfs(node: TreeNode | null): void {
  if (node === null) {
    return;
  }

  process(node); // Process the current node.
  dfs(node.left); // Traverse the left subtree.
  dfs(node.right); // Traverse the right subtree.
}

function process(node: TreeNode): void {
  // Implement your processing logic here
  console.log(node.val);
}
```

Time complexity: DFS visits each node, resulting in an O(n) time complexity.

The space complexity depends on recursion depth — the height h of the tree.
In the worst case (skewed tree), h = n; in a balanced tree, h ≈ log(n).

```js
function bfs(root: TreeNode | null): void {
  if (root === null) {
    return;
  }

  const queue: TreeNode[] = [root];

  while (queue.length > 0) {
    const node = queue.shift()!;
    process(node); // Process the current node.

    if (node.left) {
      // Add the left child to the queue.
      queue.push(node.left);
    }

    if (node.right) {
      // Add the right child to the queue.
      queue.push(node.right);
    }
  }
}
```

BFS also visits all nodes once, so time is O(n).
Space depends on the queue size — at worst, it holds all nodes at the deepest level, which can be up to n/2 nodes.
