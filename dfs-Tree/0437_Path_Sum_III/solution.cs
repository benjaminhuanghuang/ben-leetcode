public class Solution437 {
    public int PathSum(TreeNode root, int sum) {
        if (root == null)
            return 0;
        int res = PathTraverse(root, sum);
        res += this.PathSum(root.left, sum);
        res += this.PathSum(root.right, sum);

        return res;
    }

    private int PathTraverse(TreeNode root, int val)
    {
        if (root == null)
            return 0;
        int res = root.val == val ? 1:0;
        res += PathTraverse(root.left, val - root.val);
        res += PathTraverse(root.right, val - root.val);
        return res;
    }
}