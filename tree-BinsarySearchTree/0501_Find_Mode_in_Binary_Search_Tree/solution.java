package cn.huang.leetcode;
/*
    501. Find Mode in Binary Search Tree
 */
import cn.huang.leetcode.common.TreeNode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class LC_0501_FindModeinBST {
    private Map<Integer, Integer> map;

    private int max = 0;

    public int[] findMode(TreeNode root) {
        if (root == null)
            return new int[0];
        this.map = new HashMap<>();

        inorder(root);

        List<Integer> list = new LinkedList<>();
        for (int key : map.keySet()) {
            if (map.get(key) == max)
                list.add(key);
        }

        int[] res = new int[list.size()];
        for (int i = 0; i < res.length; i++)
            res[i] = list.get(i);
        return res;
       }

    private void inorder(TreeNode node) {
        if (node.left != null)
            inorder(node.left);
        map.put(node.val,
                map.getOrDefault(node.val, 0) + 1);
        max = Math.max(max, map.get(node.val));
        if (node.right != null)
            inorder(node.right);
    }
}
