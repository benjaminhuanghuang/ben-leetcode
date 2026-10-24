using System.Text;
public class Solution606
{
    public string Tree2str(TreeNode t)
    {
        StringBuilder sb = new StringBuilder();
        this.Tree2strHelper(t, sb);
        return sb.ToString();
    }

    public void Tree2strHelper(TreeNode t, StringBuilder sb)
    {
        if (t != null)
        {
            sb.Append(t.val.ToString());
            if (t.left != null || t.right != null)
                sb.Append("(");
            Tree2strHelper(t.left, sb);
            if (t.left != null || t.right != null)
                sb.Append(")");
            if (t.right != null)
            {
                sb.Append("(");
                Tree2strHelper(t.right, sb);
                sb.Append(")");
            }
        }
    }
}