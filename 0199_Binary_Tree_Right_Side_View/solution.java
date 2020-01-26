package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

 */
public class LC_0199_BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        // 层次遍历，只需要记录本层结点个数即可
        int curNum = 1;
        // 下一层的节点数
        int nextNum = 0;

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (curNum == 1)
                res.add(node.val);
            curNum--;
            if (node.left != null) {
                q.offer(node.left);
                nextNum++;
            }
            if (node.right != null) {
                q.offer(node.right);
                nextNum++;
            }
            if (curNum == 0) {
                curNum = nextNum;
                nextNum = 0;
            }
        }

        return res;
    }

    public List<Integer> rightSideView_better(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int n = q.size();
            while (n-- > 0) {
                root = q.poll();
                if (root.left != null)
                    q.add(root.left);
                if (root.right != null)
                    q.add(root.right);
                if (n == 0)
                    res.add(root.val);  //将该层的最右一个节点添加到结果集中
            }
        }

        return res;
    }
}
