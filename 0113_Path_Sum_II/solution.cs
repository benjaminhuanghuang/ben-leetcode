/*
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
using System.Collections.Generic;

public class Solution113 {
    private List<IList<int>> resint = new List<IList<int>>(); 
    public IList<IList<int>> PathSum(TreeNode root, int sum)
    {
        PathSumHelper(root, sum, new List<int>());
        return resint;
    }

    private void PathSumHelper(TreeNode root, int sum, List<int> result)
    {
        if (root == null) 
            return;
        if (root.left == null && root.right == null)
        {
            if (sum == root.val)
            {
                var cpy = new List<int>(result) {root.val};
                resint.Add(cpy);
            }
            return;
        }

        result.Add(root.val);
        PathSumHelper(root.left, sum - root.val, result);
        PathSumHelper(root.right, sum - root.val, result);
        result.RemoveAt(result.Count - 1);
    }
}