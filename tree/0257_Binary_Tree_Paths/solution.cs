/*
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

*/
using System.Collections.Generic;

public class Solution257 {
    public IList<string> BinaryTreePaths(TreeNode root) {
        List<string> res = new List<string>();
        if (root == null) {
            return res;
        }
        if (root.left == null && root.right == null) {
            res.Add(root.val.ToString());
            return res;
        }
        var left = BinaryTreePaths(root.left);
        var right = BinaryTreePaths(root.right);
        foreach (string path in left) {
            res.Add(root.val.ToString() + "->" + path);
        }
        foreach (string path in right) {
            res.Add(root.val.ToString() + "->" + path);
        }
        return res;
    }
}