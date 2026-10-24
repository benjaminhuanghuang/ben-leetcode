using System;

public class Solution337 {
    public int Rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
         
        if (root.left == null && root.right == null) {
            return root.val;
        }
         
         
        // case1: rob the root
        int leftMax = 0;
        int rightMax = 0;
         
        if (root.left != null) {
            leftMax = Rob(root.left.left) + Rob(root.left.right);
        }
         
        if (root.right != null) {
            rightMax = Rob(root.right.left) + Rob(root.right.right);
        }
         
        int maxRoot = root.val + leftMax + rightMax;
         
        // case 2: not rob the root
        leftMax = Rob(root.left);
        rightMax = Rob(root.right);
         
        int maxNoRoot = leftMax + rightMax;
         
        return Math.Max(maxRoot, maxNoRoot);
    }
}