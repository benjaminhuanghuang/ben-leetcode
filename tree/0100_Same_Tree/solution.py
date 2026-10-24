'''
100. Same Tree
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
'''


def is_tree_same(t1, t2):
    if t1 is None and t2 is None:
        return True

    if t1 and t2 and t1.val == t2.val:
        return is_tree_same(t1.left, t2.left) and is_tree_same(t1.right, t2.right)

    return False


def is_tree_same_dfs(t1, t2):
    if t1 is None and t2 is None:
        return True

    stack = [(t1, t2)]
    while stack:
        n1, n2 = stack.pop()
        if n1 == None or n2 == None:
            continue
        elif n1 and n2 and n1.val == n2.val:
            stack.append(n1.left, n2.left)
            stack.append(n1.righ, n2.right)
        else:
            return False
    return True
