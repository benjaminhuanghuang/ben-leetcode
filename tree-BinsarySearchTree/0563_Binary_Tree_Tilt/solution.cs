using System;
public class Solution563
{
    private int sum = 0;
    public int FindTilt(TreeNode root)
    {
        if (root == null)
            return 0;

        SubTreeSum(root);
        return sum;
    }

    private int SubTreeSum(TreeNode node)
    {
        if (node == null)
            return 0;

        int sumLeft = SubTreeSum(node.left);
        int sumRight = SubTreeSum(node.right);
        this.sum += Math.Abs(sumLeft - sumRight);
        return node.val + sumLeft + sumRight;
    }
}