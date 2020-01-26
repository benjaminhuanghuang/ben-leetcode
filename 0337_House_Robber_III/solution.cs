/*
337. House Robber III
The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root." Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
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