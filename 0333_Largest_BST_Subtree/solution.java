package cn.huang.leetcode;
/*
333. Largest BST Subtree

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),

where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:

    10
    / \
   5  15
  / \   \
 1   8   7

The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree's size, which is 3.



Hint:

    You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree,
    which will result in O(nlogn) time complexity.

 */


import cn.huang.leetcode.common.TreeNode;

/*
二分树的最大BST，所谓BBST就是满足左<根<右的二分树，我们需要返回这个二分搜索子树的节点个数。
题目中给的提示说我们可以用之前那道Validate Binary Search Tree的方法来做，时间复杂度为O(n2)，
这种方法是把每个节点都当做根节点，来验证其是否是二叉搜索数，并记录节点的个数，若是二叉搜索树，就更新最终结果

https://www.programcreek.com/2014/07/leetcode-largest-bst-subtree-java/

http://www.cnblogs.com/grandyang/p/5188938.html
 */
public class LC_0333_LargestBSTSubtree {
    public int largestBSTSubtree(TreeNode root) {
        if (root == null)
            return 0;
        if (isValid(root, Integer.MAX_VALUE, Integer.MIN_VALUE))
            return count(root);
        return Math.max(largestBSTSubtree(root.left), largestBSTSubtree(root.right));
    }

    boolean isValid(TreeNode root, int mn, int mx) {
        if (root == null)
            return true;
        if (root.val <= mn || root.val >= mx)
            return false;
        return isValid(root.left, mn, root.val) && isValid(root.right, root.val, mx);
    }

    int count(TreeNode root) {
        if (root == null)
            return 0;
        return count(root.left) + count(root.right) + 1;
    }

    /*
        http://www.cnblogs.com/grandyang/p/5188938.html
        题目中的Follow up让我们用O(n)的时间复杂度来解决问题, 只允许我们遍历一次整个二叉树，
    */
    int res = 0, mn = Integer.MIN_VALUE, mx = Integer.MAX_VALUE;

    public int largestBSTSubtree_ON(TreeNode root) {
        boolean d = isValidBST(root, mn, mx, res);
        return res;
    }

    boolean isValidBST(TreeNode root, int mn, int mx, int res) {
        if (root == null)
            return true;
        int left_n = 0, right_n = 0, left_mn = Integer.MIN_VALUE;
        int right_mn = Integer.MIN_VALUE, left_mx = Integer.MAX_VALUE, right_mx = Integer.MAX_VALUE;
        boolean left = isValidBST(root.left, left_mn, left_mx, left_n);
        boolean right = isValidBST(root.right, right_mn, right_mx, right_n);
        if (left && right) {
            if ((root.left != null || root.val > left_mx) && (root.right != null || root.val < right_mn)) {
                res = left_n + right_n + 1;
                mn = root.left != null ? left_mn : root.val;
                mx = root.right != null ? right_mx : root.val;
                return true;
            }
        }
        res = Math.max(left_n, right_n);
        return false;
    }


}
