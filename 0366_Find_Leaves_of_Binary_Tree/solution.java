package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.*;

/*
366. Find Leaves of Binary Tree

Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.

Example:
Given binary tree 

          1
         / \
        2   3
       / \
      4   5
Returns [4, 5, 3], [2], [1].

Explanation:

1. Remove the leaves [4, 5, 3] from the tree

          1
         /
        2
2. Remove the leaf [2] from the tree

          1
3. Remove the leaf [1] from the tree

          []
Returns [4, 5, 3], [2], [1].

 */

/*
The key to solve this problem is converting the problem to be finding the index of the element in the result list.
 */
public class LC_0366_FindLeavesofBinaryTree {

    public List<List<Integer>> findLeaves(TreeNode root) {
        HashMap<TreeNode, Integer> map = new HashMap<>();
        helper(root, map);  // every node get an order

        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        HashMap<Integer, HashSet<TreeNode>> reversed = new HashMap<>();

        for (Map.Entry<TreeNode, Integer> entry : map.entrySet()) {
            min = Math.min(min, entry.getValue());
            max = Math.max(max, entry.getValue());

            HashSet<TreeNode> set = reversed.getOrDefault(entry.getValue(), new HashSet<TreeNode>());
            set.add(entry.getKey());
            reversed.put(entry.getValue(), set);
        }


        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for (int i = min; i <= max; i++) {
            HashSet<TreeNode> set = reversed.get(i);
            ArrayList<Integer> l = new ArrayList<>();
            for (TreeNode td : set) {
                l.add(td.val);
            }
            result.add(l);
        }

        return result;
    }

    private int helper(TreeNode root, HashMap<TreeNode, Integer> map) {
        if (root == null) {
            return 0;
        }

        int left = helper(root.left, map);
        int right = helper(root.right, map);

        int order = Math.max(left, right) + 1;
        map.put(root, order);
        return order;
    }

    public List<List<Integer>> findLeaves2(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        helper(result, root);
        return result;
    }


    // traverse the tree bottom-up recursively
    private int helper(List<List<Integer>> list, TreeNode root) {
        if (root == null)
            return -1;
        int left = helper(list, root.left);
        int right = helper(list, root.right);
        int curr = Math.max(left, right) + 1;
// the first time this code is reached is when curr==0,
//since the tree is bottom-up processed.
        if (list.size() <= curr) {
            list.add(new ArrayList<Integer>());
        }
        list.get(curr).add(root.val);
        return curr;
    }
}
