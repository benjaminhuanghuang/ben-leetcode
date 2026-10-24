package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.Stack;

/*
230. Kth Smallest Element in a BST



 */
public class LC_0230_KthSmallestElementinaBST {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;

        while(node != null)
        {
            stack.push(node);
            node = node.left;
        }
        int x = 1;
        while(stack.size() > 0 && x <=k)
        {
            node = stack.pop();
            x ++;
            TreeNode right = node.right;
            while (right != null)
            {
                stack.push(right);
                right = right.left;
            }
        }
        return node.val;
    }
}
