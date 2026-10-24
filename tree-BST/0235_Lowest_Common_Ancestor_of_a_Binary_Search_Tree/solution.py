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