package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
652. Find Duplicate Subtrees

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the
root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4

The following are two duplicate subtrees:

      2
     /
    4

and

    4

Therefore, you need to return above trees' root in the form of a list.
 */
public class LC_0652_FindDuplicateSubtrees {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        HashMap<String, TreeNode> map = new HashMap<>();
        List<TreeNode> list = new ArrayList<>();
        if (root == null)
            return list;
        preorderSerialize(root, map);

        for (String key : map.keySet()) {
            if (map.get(key) != null) {
                list.add(map.get(key));
            }
        }
        return list;
    }

    public String preorderSerialize(TreeNode root, HashMap<String, TreeNode> map) {
        if (root == null) return "#";

        String serializedStr = root.val + preorderSerialize(root.left, map) + preorderSerialize(root.right, map);
        if (map.containsKey(serializedStr)) {
            map.put(serializedStr, root);
        } else {
            map.put(serializedStr, null);
        }

        return serializedStr;
    }

    private boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;

        if (p == null || q == null)
            return false;

        if (p.val != q.val)
            return false;

        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
