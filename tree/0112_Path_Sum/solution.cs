public class Solution112 {
    public bool HasPathSum(TreeNode root, int sum) {
        if (root == null)
        {
            return false;
        }
        if (root.left == null && root.right == null)
        {
            return sum == root.val;
        }

        return this.HasPathSum(root.left, sum - root.val) || this.HasPathSum(root.right, sum - root.val);
    }
}