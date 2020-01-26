/*
112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

public class Solution112 {
    public bool HasPathSum(TreeNode root, int sum) {
        if (root == null)
        {
            return false;
        }
        if (root.left == null && root.right == null)
        {
            return sum == root.val;
        }

        return this.HasPathSum(root.left, sum - root.val) || this.HasPathSum(root.right, sum - root.val);
    }
}