package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
968. Binary Tree Cameras
Given a binary tree, we install cameras on the nodes of the tree.

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.



Example 1:

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:

Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid
configurations of camera placement.


Note:

    The number of nodes in the given tree will be in the range [1, 1000].
    Every node has value 0.


 */
public class LC_0968_BinaryTreeCameras {
    public int minCameraCover(TreeNode root) {
        int[] ret = new int[1];
        helper(root, null, ret);
        return ret[0];
    }

    int helper(TreeNode root, TreeNode parent, int[] res) {
        if(root == null)
            return -1;

        int left = helper(root.left, root, res);
        int right = helper(root.right, root, res);

        if(left == -1 && right == -1) {
            if(parent == null)
                res[0]++;
            return 0;
        }
        if(left == 0 || right == 0) {
            res[0]++;
            return 1;
        }

        return -1;
    }
}
