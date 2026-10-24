package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
    257. Binary Tree Paths
 */
public class LC_0257_BinaryTreePaths {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        if(root == null)
            return res;

        if(root.left == null && root.right == null)
        {
            res.add(root.val + "");
        }
        if(root.left!=null)
        {
            List<String> leftPath = binaryTreePaths(root.left);
            for(String path:leftPath)
            {
                res.add(root.val + "->" + path);
            }
        }
        if(root.right!=null)
        {
            List<String> rightPath = binaryTreePaths(root.right);
            for(String path:rightPath)
            {
                res.add(root.val + "->" + path);
            }
        }

        return res;
    }
}
