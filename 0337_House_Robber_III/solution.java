package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.HashMap;

/*
337. House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses
in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

 */
public class LC_0337_HouseRobber_III {
    /*
    为了获得rob(root),需要计算rob(root.left), rob(root.right), rob(root.left.left), rob(root.left.right), rob(root.right.left), rob(root.right.right);
    但是我们计算rob(root.left)的时候我们又会去计算一遍rob(root.left.left), rob(root.left.right)，这样就重复计算了，
    所以我们考虑将已经计算过的结果存起来，如果下次需要直接存取就行了，而不需要重复计算一遍，

     */
    public int rob(TreeNode root) {
        if(root == null)
            return 0;
        HashMap<TreeNode, Integer> map = new HashMap<>();
        return helper(root, map);
    }

    private int helper(TreeNode root, HashMap<TreeNode, Integer> map) {
        if(root == null)
            return 0;
        if(map.containsKey(root))
            return map.get(root);

        int val = root.val;

        if(root.left != null)
            val += helper(root.left.left, map) + helper(root.left.right, map);

        if(root.right != null)
            val += helper(root.right.left, map) + helper(root.right.right, map);

        val = Math.max(val, helper(root.left, map) + helper(root.right, map));

        map.put(root, val);

        return val;
    }
}
