package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeLinkNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
117. Populating Next Right Pointers in Each Node II
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    Recursive approach is fine, implicit stack space does not moves as extra space for this problem.

Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL


 */
public class LC_0117_PopulatingNextRightPointersinEachNode_II {
    /*
    BFS, easy but not constant space
    Complexity: time O(N) space O(N) - queue
     */
    public void connect(TreeLinkNode root) {
        if (root == null)
            return;

        Queue<TreeLinkNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int count = q.size();
            List<TreeLinkNode> layer = new ArrayList<>();
            for (int i = 0; i < count; i++) {
                TreeLinkNode node = q.poll();
                layer.add(node);
                if (node.left != null)
                    q.add(node.left);
                if (node.right != null)
                    q.add(node.right);
            }

            for (int i = 0; i < count - 1; i++) {
                layer.get(i).next = layer.get(i + 1);
            }
        }
    }

    /*
    http://rainykat.blogspot.com/2017/02/leetcodef-117-populating-next-right.html
    Do not use layer
     */
    public void connect_better(TreeLinkNode root) {
        if (root == null)
            return;

        Queue<TreeLinkNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                TreeLinkNode node = q.poll();
                if (i < count - 1) {
                    TreeLinkNode next = q.peek();
                    node.next = next;
                }
                if (node.left != null)
                    q.add(node.left);
                if (node.right != null)
                    q.add(node.right);
            }
        }
    }

    /*
    http://rainykat.blogspot.com/2017/02/leetcodef-117-populating-next-right.html
    Iteration - use dummy node to keep record of the next level's root to refer
             pre travel current level by referring to root in the level above
      Complexity: time O(N) space O(1)
     */
    public void connect2(TreeLinkNode root) {
        TreeLinkNode headerOfNextLayer = new TreeLinkNode(-1);
        TreeLinkNode layerItrator = headerOfNextLayer;//record next root
        while (root != null) {
            if (root.left != null) {
                layerItrator.next = root.left;
                layerItrator = layerItrator.next;
            }
            if (root.right != null) {
                layerItrator.next = root.right;
                layerItrator = layerItrator.next;
            }
            root = root.next; //reach end, update new root & reset dummy
            if (root == null) {
                root = headerOfNextLayer.next;
                layerItrator = headerOfNextLayer;
                headerOfNextLayer.next = null;
            }
        }
    }
}
