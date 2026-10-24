package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.*;

/*

103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]


 */
public class LC_0103_BinaryTreeZigzagLevelOrderTraversal {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();

        if(root == null)
            return res;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean left2right = true;
        while(!q.isEmpty())
        {
            int count = q.size();
            List<Integer> layer = new ArrayList<>();
            for(int i =0; i<count; i++) {
                TreeNode node = q.poll();
                layer.add(node.val);
                if(node.left != null)
                    q.add(node.left);
                if(node.right != null)
                    q.add(node.right);
            }
            if(!left2right)
            {
                Collections.reverse(layer);
            }
            res.add(layer);
            left2right = !left2right;
        }

        return res;
    }
}
