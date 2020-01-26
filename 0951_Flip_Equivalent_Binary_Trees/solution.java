package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*

951. Flip Equivalent Binary Trees

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.



Example 1:

Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Flipped Trees Diagram


Note:

Each tree will have at most 100 nodes.
Each value in each tree will be a unique integer in the range [0, 99].

 */
public class LC_0951_FlipEquivalentBinaryTrees {
    /*
    1：当前节点都为None，返回True；
    2：当前节点都不为None，此时若两个节点的值不相等，返回False，反之，递归到下一层，比较左右子结点，分为两种情况
        （左节点对左节点，右节点对右节点或者左节点对右节点，右节点对左节点），一种情况为True，就返回True；
    3：一个为None，一个不为None，返回False。
     */
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null)
            return true;
        else if (root1 != null && root2 != null)
            if (root1.val != root2.val)
                return false;
            else
                return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)) ||
                        (flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left));
        else
            return false;
    }
}
