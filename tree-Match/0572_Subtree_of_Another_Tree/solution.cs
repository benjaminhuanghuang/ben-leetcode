public class Solution572
{
    public bool IsSubtree(TreeNode s, TreeNode t)
    {
        if (t == null)
        {
            return true;
        }

        if (s == null)
        {
            return false;
        }
        if (this.IsSameTree(s, t))
        {
            return true;
        }
        return this.IsSubtree(s.left, t) || this.IsSubtree(s.right, t);
    }

    private bool IsSameTree(TreeNode s, TreeNode t)
    {
        if (s == null && t == null)
        {
            return true;
        }

        if (s == null || t == null)
        {
            return false;
        }

        if (s.val != t.val)
        {
            return false;
        }

        return this.IsSameTree(s.left, t.left)
            && this.IsSameTree(s.right, t.right);
    }
}