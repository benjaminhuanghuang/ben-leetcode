package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
    107. Binary Tree Level Order Traversal II
 */
public class LC_0107_BinaryTreeLevelOrderTraversal_II {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();

        if(root == null)
            return res;

        List<TreeNode> layer = new ArrayList<>();
        layer.add(root);
        while(layer.size() > 0)
        {   List<Integer> values = new ArrayList<>();
            List<TreeNode> nextLayer = new ArrayList<>();
            for(TreeNode n:layer)
            {
                values.add(n.val);
                if(n.left != null)
                    nextLayer.add(n.left);
                if(n.right != null)
                    nextLayer.add(n.right);
            }
            res.add(0, values);
            layer = nextLayer;
        }

        return res;
    }
}
