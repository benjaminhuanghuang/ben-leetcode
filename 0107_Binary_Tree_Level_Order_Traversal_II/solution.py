'''
107. Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

'''


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
