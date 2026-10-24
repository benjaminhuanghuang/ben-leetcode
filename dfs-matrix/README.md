# Depth-First Search with Matrix

## Template

```js
function dfs(root, target) {
  if (!root) return null;
  if (root.val == target) return root;

  left = dfs(root.left);
  if (left != null) return left;
  right = dfs(root.right);
  return right;
}
```
