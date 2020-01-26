/*
156. Binary Tree Upside Down

Given a binary tree where all the right nodes are either leaf nodes with a sibling 
(a left node that shares the same parent node) or empty, flip it upside down and 
turn it into a tree where the original right nodes turned into left leaf nodes. 
Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
*/

/**
 * Definition for binary tree
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */



public class Solution156 {
    
    public TreeNode upsideDownBinaryTree(TreeNode root) 
    {
        if (root == null || root.left == null)
            return root;
        TreeNode newRoot = upsideDownBinaryTree(root.left);//新树根在最左
        TreeNode rightMostIterator = newRoot;//找新根的最右，挂两个旋转得来的的孩子
        while (rightMostIterator.right != null) 
        {
            rightMostIterator = rightMostIterator.right;
        }
        rightMostIterator.left = root.right;//原右孩子拖家带口投奔新根的左边
        rightMostIterator.right = new TreeNode(root.val);//原root诛九族去右边

        return newRoot;
    }
    //  Good!
    public TreeNode UpsideDownBinaryTree_Recursively(TreeNode root) 
    {  
        if (root == null)  
            return null;  
        TreeNode parent = root, left = root.left, right = root.right;  
        if (left != null) {  
            TreeNode ret = UpsideDownBinaryTree_Recursively(left);  
            left.left = right;  
            left.right = parent;  
            return ret;  
        }  
        return root;  // left == null
    } 

    public TreeNode UpsideDownBinaryTree_Iteratively(TreeNode root) 
    {  
        TreeNode node = root, parent = null, right = null;  
        while (node != null) {  
            TreeNode left = node.left;  
            node.left = right;  
            right = node.right;  
            node.right = parent;  
            parent = node;  
            node = left;  
        }  
        return parent;  
    } 
}