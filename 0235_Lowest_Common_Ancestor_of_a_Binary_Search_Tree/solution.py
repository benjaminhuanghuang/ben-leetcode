'''
235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes
v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)."

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
since a node can be a descendant of itself according to the LCA definition.


reference
 https://www.youtube.com/watch?v=LFjCr2yDJdc
'''


def lowest_common_ancestor(root, p, q):
    if root == None:
        return None
    if p.val > root.val and q.val > root.val:
        return lowest_common_ancestor(root.right, p, q)
    if p.val < root.val and q.val < root.val:
        return lowest_common_ancestor(root.left, p, q)

    return root

'''
static Node lca_not_good_but_work(Node root,int v1,int v2)
    {
        if (root == null)
            return null;

        if (v1 == root.data || v2 == root.data)
            return root;
        if (v1 < root.data && v2 >= root.data)
            return root;
        if (v1 >= root.data && v2 < root.data)
            return root;

        if (v1 < root.data && v2 < root.data)
            return lca(root.left, v1, v2);
        if (v1 > root.data && v2 > root.data)
            return lca(root.right, v1, v2);
        return null;
    }

'''