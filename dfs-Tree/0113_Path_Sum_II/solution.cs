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