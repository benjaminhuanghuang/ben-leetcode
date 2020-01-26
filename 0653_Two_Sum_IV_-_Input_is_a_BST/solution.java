package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/*
    653. Two Sum IV - Input is a BST
 */
public class LC_0653_TwoSumIV_InputisaBST {
    public boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;
        List<Integer> list = new ArrayList<>();
        inOrder(root, list);

        int i = 0, j = list.size() - 1;
        while (i < j) {
            int sum = list.get(i) + list.get(j);
            if (sum == k) return true;
            if (sum < k) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }

    // 中根遍历 BST，能得到一个从小到大排序的 list
    private void inOrder(TreeNode root, List<Integer> list) {
        if (root == null) return;

        inOrder(root.left, list);
        list.add(root.val);
        inOrder(root.right, list);
    }

    public boolean findTarget_V2(TreeNode root, int k) {
        HashSet<Integer> hashSet = new HashSet<Integer>();
        return find(root, k, hashSet);
    }

    public boolean find(TreeNode node, int k, HashSet<Integer> hashSet) {
        if (node == null) {
            return false;
        }
        if (hashSet.contains(k - node.val)) {
            return true;
        }
        hashSet.add(node.val);
        return find(node.left, k, hashSet) || find(node.right, k, hashSet);
    }
}
