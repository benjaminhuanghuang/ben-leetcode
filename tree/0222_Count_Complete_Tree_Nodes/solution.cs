public class Solution222 {
    // Time Limit Exceeded
    public int CountNodes(TreeNode root) {
        if(root == null)
            return 0;
        int count = 1;
        if (root.left != null)
            count += CountNodes(root.left);
        if (root.right != null)
            count += CountNodes(root.right);  

        return count;  
    }
    
    public int CountNodes_2(TreeNode root) {
        if(root == null)
            return 0;
        int leftH = GetHeight(root, true);
        int rightH = GetHeight(root, false);

        if (leftH == rightH)
            return (1<< leftH) - 1;
        else
            return CountNodes_2(root.left) + CountNodes_2(root.right) + 1;
    }

    private int GetHeight(TreeNode root, bool isLeft)
    {
        int hight = 0;
        while(root != null)
        {
            if (isLeft)
                root = root.left;
            else
                root = root.right;
            hight ++;
        }
        return hight;
    }
}