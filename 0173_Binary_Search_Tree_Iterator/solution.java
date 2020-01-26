package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.Stack;

/*
173. Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Example:

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false


 */
public class LC_0173_BinarySearchTreeIterator {
    public class BSTIterator {
        private Stack<TreeNode> stack = new Stack<TreeNode>();

        public BSTIterator(TreeNode root) {
            help(root);
        }

        /**
         * @return whether we have a next smallest number
         */
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        /**
         * @return the next smallest number
         */
        public int next() {
            TreeNode minCurrent = stack.pop();
            help(minCurrent.right);

            return minCurrent.val;
        }

        private void help(TreeNode root)
        {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
        }
    }
}
