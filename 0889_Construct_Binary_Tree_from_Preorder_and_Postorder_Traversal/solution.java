package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Stack;

/*

889. Construct Binary Tree from Preorder and Postorder Traversal

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.



Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

 */
public class LC_0889_ConstructBinaryTreefromPreorderandPostorderTraversal {
    /*
    pre-order: root, (left), (right)
    post-order:  (left), (right),root
     */
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        if (pre == null || pre.length == 0)
            return null;
        TreeNode root = new TreeNode(pre[0]);
        if (pre.length == 1)
            return root;

        int leftRoot = pre[1];

        int lengthOfLeftTree = getElementIndex(post, leftRoot) + 1;   // length = index  +1;
        root.left = constructFromPrePost(Arrays.copyOfRange(pre, 1, lengthOfLeftTree + 1), Arrays.copyOfRange(post, 0, lengthOfLeftTree));
        root.right = constructFromPrePost(Arrays.copyOfRange(pre, lengthOfLeftTree + 1, pre.length), Arrays.copyOfRange(post, lengthOfLeftTree, post.length));

        return root;
    }

    private int getElementIndex(int[] array, int value) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == value)
                return i;
        }
        return -1;
    }
}
