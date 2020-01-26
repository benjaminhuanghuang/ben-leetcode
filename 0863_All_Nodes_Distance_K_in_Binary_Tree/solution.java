package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.*;

/*
863. All Nodes Distance K in Binary Tree

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.
The answer can be returned in any order.



Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation:
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.



Note:

    The given tree is non-empty.
    Each node in the tree has unique values 0 <= node.val <= 500.
    The target node is a node in the tree.
    0 <= K <= 1000.


 */

/*
https://leetcode.com/articles/all-nodes-distance-k-in-binary-tree/#
 */
public class LC_0863_AllNodesDistanceKinBinaryTree {
    List<Integer> ans;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        ans = new LinkedList();
        dfs(root, target, K);
        return ans;
    }

    // Return vertex distance from node to target if exists, else -1
    // Vertex distance: the number of vertices on the path from node to target
    public int dfs(TreeNode node, TreeNode target, int K) {
        if (node == null)
            return -1;
        else if (node == target) {
            subtree_add(node, 0, K);
            return 1;
        } else {
            int L = dfs(node.left, target, K), R = dfs(node.right, target, K);
            if (L != -1) {
                if (L == K)
                    ans.add(node.val);
                subtree_add(node.right, L + 1, K);
                return L + 1;
            } else if (R != -1) {
                if (R == K)
                    ans.add(node.val);
                subtree_add(node.left, R + 1, K);
                return R + 1;
            } else {
                return -1;
            }
        }
    }

    // Add all nodes 'K - dist' from the node to answer.
    public void subtree_add(TreeNode node, int dist, int K) {
        if (node == null) return;
        if (dist == K)
            ans.add(node.val);
        else {
            subtree_add(node.left, dist + 1, K);
            subtree_add(node.right, dist + 1, K);
        }
    }
}
