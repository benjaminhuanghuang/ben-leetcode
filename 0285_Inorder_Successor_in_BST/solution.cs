/*
285. Inorder Successor in BST 

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

*/
public class Solution285
{
    /*
     if root.val > p.val; root can be possible answer, store it and go left
     if root.val <= p.val; root can not be answer, go right.
    */
    public TreeNode InorderSuccessor(TreeNode root, TreeNode p)
    {
        TreeNode res = null;
        while (root != null)
        {
            if (root.val <= p.val)
            {
                root = root.right;
            }
            else
            {
                // root.val <= p.val, root can be possible answer
                res = root;
                root = root.left;
            }
        }

        return res;
    }
}