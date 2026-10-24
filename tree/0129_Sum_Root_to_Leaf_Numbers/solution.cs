using System.Linq;
using System.Collections.Generic;

public class Solution129 {
    public int SumNumbers(TreeNode root) {
        if(root == null)
        {
            return 0;
        }

        var listOfString = SumNumbersRecursion(root);

        return listOfString.Sum(item => int.Parse(item));
    }
    private List<string> SumNumbersRecursion(TreeNode root)
    {
        var res = new List<string>();
        if (root.left == null && root.right == null)
        {
            res.Add(root.val.ToString());
            return res;
        }

        var left = root.left != null ? SumNumbersRecursion(root.left) : new List<string>();
        var right = root.right != null ? SumNumbersRecursion(root.right) : new List<string>();

        res.AddRange(left.Select(item => root.val + item));

        res.AddRange(right.Select(item => root.val + item));

        return res;
    }

    //use backtracking
    public int SumNumbers_2(TreeNode root)
    {
        var res = 0;
        this.SumNumbersHelper(root, 0, ref res);
        return res;
    }

    private void SumNumbersHelper(TreeNode root, int solution, ref int res)
    {
        if (root == null)
        {
            return;
        }
        if (root.left == null && root.right == null)
        {
            res += solution * 10 + root.val;
            return;
        }

        solution = solution * 10 + root.val;
        this.SumNumbersHelper(root.left, solution, ref res);
        solution /= 10;

        solution = solution * 10 + root.val;
        this.SumNumbersHelper(root.right, solution, ref res);
        solution /= 10;
    }
}