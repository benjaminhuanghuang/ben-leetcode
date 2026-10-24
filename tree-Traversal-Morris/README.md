# Morris Traversal

Morris Traversal is a binary tree traversal algorithm that allows you to traverse a tree without using recursion or a stack, i.e., in O(1) extra space, by temporarily modifying the tree with “threads.”

It’s named after Joseph M. Morris, who introduced it in 1979.

Normally, traversing a binary tree (in-order, pre-order, post-order) uses:
Recursion with O(h) space, or Stack with O(h) space, where h = tree height

Morris Traversal avoids this by:
Using the tree’s null left or right pointers as temporary links (“threads”) to remember where to go next
After finishing, the tree is restored to its original shape

## How it works (In-Order Version)

In-order: Left → Node → Right

```js
current = root

while current != null:
    if current.left == null:
        visit(current)          // Process current node
        current = current.right
    else:
        predecessor = current.left
        // Find rightmost node in left subtree
        while predecessor.right != null && predecessor.right != current:
            predecessor = predecessor.right

        if predecessor.right == null:
            // First time visiting left subtree: create thread
            predecessor.right = current
            current = current.left
        else:
            // Second time visiting: left subtree done
            predecessor.right = null  // Remove thread
            visit(current)            // Process current node
            current = current.right
```

## Time & Space Complexity

Time: O(n), Each node is visited at most twice
Space: O(1), Only uses pointers, no stack or recursion
