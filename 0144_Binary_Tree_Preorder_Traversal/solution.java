package cn.huang.leetcode;
/*
144. Binary Tree Preorder Traversal

 */
import cn.huang.leetcode.common.TreeNode;

import java.util.*;

public class LC_0144_BinaryTreePreorderTraversal {
    public List<Integer> recursion(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        result.add(root.val);
        if (root.left != null) {
            result.addAll(recursion(root.left));
        }
        if (root.right != null) {
            result.addAll(recursion(root.right));
        }
        return result;
    }

    public List<Integer> iteration(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        if (root != null) {
            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);

            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                result.add(node.val);

                // push right node firstly, pop left before right
                if (node.right != null) {
                    stack.add(node.right);
                }
                if (node.left != null) {
                    stack.add(node.left);
                }
            }
        }

        return result;
    }
}
