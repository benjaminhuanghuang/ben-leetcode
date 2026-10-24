package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
94. Binary Tree Inorder Traversal

Follow up: Recursive solution is trivial, could you do it iteratively?
 */
public class LC_0094_BinaryTreeInorderTraversal {
    //https://www.youtube.com/watch?v=VsxLHGUqAKs
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        Stack<TreeNode> stack = new Stack<TreeNode>();

        TreeNode node = root;
        while (!stack.isEmpty() || node != null) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }

            node = stack.pop();
            ans.add(node.val);
            node = node.right;
        }
        return ans;
    }

    // https://www.youtube.com/watch?v=wGXB9OWhPTg
    public List<Integer> inorderTraversal_Morris(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        TreeNode current = root;
        while (current != null) {
            if (current.left == null) {
                // left is null then access the node and go to right.
                ans.add(current.val);
                current = current.right;
            } else {
                // Find the predecessor
                TreeNode predecessor = current.left;
                while (predecessor.right != current && predecessor.right !=null)
                {
                    predecessor = predecessor.right;
                }
                // if right node is null then go left after establishing like from predecessor to current
                if(predecessor.right == null)
                {
                    predecessor.right = current;
                    current = current.left;
                }
                else // left is already visit. go right after visiting current
                {
                    predecessor.right = null;
                    ans.add(current.val);
                    current = current.right;
                }
            }
        }
        return ans;
    }
}
