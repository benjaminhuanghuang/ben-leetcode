# Binary Search Tree

- The values are sorted when the tree is traversed in in-order.

```js
function inOrder(root) {
  if (root === null) return;
  inOrder(root.left);
  console.log(root.val);
  inOrder(root.right);
}
```
