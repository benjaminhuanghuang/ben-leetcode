package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/*
662. Maximum Width of Binary Tree

Given a binary tree, write a function to get the maximum width of the given tree.
The width of a tree is the maximum width among all levels.
The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes
(the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input:

           1
         /   \
        3     2
       / \     \
      5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:

Input:

          1
         /
        3
       / \
      5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:

Input:

          1
         / \
        3   2
       /
      5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

Example 4:

Input:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
 */

/*
给定二叉树，求二叉树的最大宽度。二叉树某层的宽度是指其最左非空节点与最右非空节点之间的跨度。
 */

public class LC_0662_MaximumWidthofBinaryTree {
    public int widthOfBinaryTree_Wrong(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();  //用于树的广度优先遍历。
        queue.add(root);
        int max = 1;
        while (!queue.isEmpty()) {
            int n = queue.size();
            max = Math.max(max, n);
            while (n >= 0) {
                TreeNode current = queue.poll();

                if (current.left != null) {
                    queue.add(current.left);
                }
                if (current.right != null) {
                    queue.add(current.right);
                }
            }
        }
        return max;
    }

    /*
    对二叉树节点进行标号，根节点标号为0；若某节点标号为c，则其左右孩子标号分别为2c, 2c + 1
    某层的宽度即为最右、最左节点标号之差+1
     */
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        Map<TreeNode, Integer> map = new HashMap<>();
        map.put(root, 0);
        int max = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            int left = 0;
            for (int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();
                int index = map.get(curr);
                if (i == 0) {
                    left = index;
                }
                if (i == size - 1) {
                    max = Math.max(max, index - left + 1);
                }
                if (curr.left != null) {
                    map.put(curr.left, 2 * index);
                    queue.add(curr.left);
                }
                if (curr.right != null) {
                    map.put(curr.right, 2 * index + 1);
                    queue.add(curr.right);
                }
            }
        }
        return max;
    }
}
