/*
404. Sum of Left Leaves [M]

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution404 {
    private int sum=0;
 
    public int SumOfLeftLeaves(TreeNode root) {
        if (root != null)
        {
            if (root.left != null)
            {
                if(root.left.left == null && root.left.right == null)
                {
                    this.sum += root.left.val;
                }
                else
                {
                    this.SumOfLeftLeaves(root.left);
                }
            }
            if (root.right != null)
            {
                this.SumOfLeftLeaves(root.right);
            }
        }

        return sum;
    }
}