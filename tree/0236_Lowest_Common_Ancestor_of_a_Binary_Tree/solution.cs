/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
two nodes v and w as the lowest node in T that has both v and w as 
descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of 
nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

public class Solution236 {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        //发现目标节点则通过返回值,标记该子树发现了某个目标结点
        if (root == null || root == p || root == q)
            return root;
        //查看左子树中是否有目标结点，没有为null    
        TreeNode left = LowestCommonAncestor(root.left, p, q);
        //查看右子树是否有目标节点，没有为null
        TreeNode right = LowestCommonAncestor(root.right, p, q);
        //都不为空，说明做右子树都有目标结点，则公共祖先就是本身
        if (left != null && right !=null)        
            return root;
        if (left != null)
            return left;
        return right;
    }
}