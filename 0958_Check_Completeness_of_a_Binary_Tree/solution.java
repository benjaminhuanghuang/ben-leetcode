package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
958. Check Completeness of a Binary Tree
Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.



Example 1:



Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:



Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.

Note:

The tree will have between 1 and 100 nodes.
 */
public class LC_0958_CheckCompletenessofaBinaryTree {
    public boolean isCompleteTree(TreeNode root) {
        if(root == null)
            return true;

        Queue<TreeNode> queue =new LinkedList<>();
        //
        boolean findNonFull = false;

        queue.add(root);
        while(!queue.isEmpty())
        {
            TreeNode node = queue.poll();

            if(node.left != null)
            {
                // If we have seen a non full node, and we see a node
                // with non-empty left child, then the given tree is not
                // a complete Binary Tree
                if(findNonFull == true)
                    return false;

                // Enqueue Left Child
                queue.add(node.left);
            }
            else
                findNonFull = true;

            if(node.right != null)
            {
                // If we have seen a non full node, and we see a node
                // with non-empty right child, then the given tree is not
                // a complete Binary Tree
                if(findNonFull == true)
                    return false;

                // Enqueue Right Child
                queue.add(node.right);

            }
            else
                findNonFull = true;
        }
        return true;
    }
}
