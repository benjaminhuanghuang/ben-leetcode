/*
222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the 
last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 在一棵完全二叉树的每一层，除最后一层外，其余各层都是填满的，并且最后一层的节点尽可能的靠左排列。
 最后一层（第h层）包含的节点个数介于[1, 2^h]区间之内。
*/

public class Solution222 {
    // Time Limit Exceeded
    public int CountNodes(TreeNode root) {
        if(root == null)
            return 0;
        int count = 1;
        if (root.left != null)
            count += CountNodes(root.left);
        if (root.right != null)
            count += CountNodes(root.right);  

        return count;  
    }
    
    public int CountNodes_2(TreeNode root) {
        if(root == null)
            return 0;
        int leftH = GetHeight(root, true);
        int rightH = GetHeight(root, false);

        if (leftH == rightH)
            return (1<< leftH) - 1;
        else
            return CountNodes_2(root.left) + CountNodes_2(root.right) + 1;
    }

    private int GetHeight(TreeNode root, bool isLeft)
    {
        int hight = 0;
        while(root != null)
        {
            if (isLeft)
                root = root.left;
            else
                root = root.right;
            hight ++;
        }
        return hight;
    }
}