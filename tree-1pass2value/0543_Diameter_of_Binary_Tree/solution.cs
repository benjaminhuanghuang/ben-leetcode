using System;

public class Solution543
{
    /*
    对根节点递归计算左右子树的Diameter，通过和类内的变量 diameter 进行比较，保存较大值。
    在每一次递归结束后，返回这棵子树的深度，根节点获取了左右子树的深度后，将二者相加就是该根节点下的Diameter。
    注意审题！length is edges！
     */
    public int DiameterOfBinaryTree(TreeNode root)
    {
        if (root == null)
            return 0;
        int diameter = 0;
        this.GetMaxDepth(root, ref diameter);
        return diameter - 1;
    }

    private int GetMaxDepth(TreeNode node, ref int diameter)
    {
        if (node == null)
            return 0;
        int depthLeft = GetMaxDepth(node.left, ref diameter) + 1;
        int depthRight = GetMaxDepth(node.right, ref diameter) + 1;

        diameter = Math.Max(depthLeft + depthRight - 1, diameter);
        return Math.Max(depthLeft, depthRight);
    }
}