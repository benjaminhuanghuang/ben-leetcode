/*
226. Invert Binary Tree


*/

public class Solution226 {
    public TreeNode InvertTree(TreeNode root) {
        if(root == null)
            return root;

        TreeNode temp = root.left;
        root.left = this.InvertTree(root.right);
        root.right = this.InvertTree(temp);
        
        return root;
    }
}