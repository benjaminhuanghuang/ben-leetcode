def max_depth(root):
    if root is None:
        return 0
    return max(max_depth(root.left), max_depth(root.right)) + 1
