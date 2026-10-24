def level_order_traversal(root):
    results = []
    if not root:
        return []
    q = [root]
    while q:
        new_q = []
        results.append([n.val for n in q])
        for node in q:
            if node.left:
                new_q.append(node.left)
            if node.right:
                new_q.append(node.right)
        q = new_q
    return list(reversed(results))
