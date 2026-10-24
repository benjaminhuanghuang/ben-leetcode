/*
450. Delete Node in a BST [Uber]


*/

public class Solution450 {
    //https://segmentfault.com/a/1190000005032508
    public TreeNode DeleteNode(TreeNode root, int key) {
        TreeNode dummy = new TreeNode(0);
        dummy.left = root;
        
        TreeNode parent = findNode(dummy, root, key);
        TreeNode node;
        if (parent.left != null && parent.left.val == key) {
            node = parent.left;
        } 
        else if (parent.right != null && parent.right.val == key) {
            node = parent.right;
        } 
        else {
            return dummy.left;
        }
        
        deleteNode(parent, node);
        
        return dummy.left;
    }

     private TreeNode findNode(TreeNode parent, TreeNode node, int value) {
        if (node == null) {
            return parent;
        }
        
        if (node.val == value) {
            return parent;
        }
        if (value < node.val) {
            return findNode(node, node.left, value);
        } else {
            return findNode(node, node.right, value);
        }
    }
    
    private void deleteNode(TreeNode parent, TreeNode node) {
        if (node.right == null) {
            if (parent.left == node) {
                parent.left = node.left;
            } 
            else {
                parent.right = node.left;
            }
        } 
        else {
            TreeNode temp = node.right;
            TreeNode father = node;
            
            while (temp.left != null) {
                father = temp;
                temp = temp.left;
            }
            
            if (father.left == temp) {
                father.left = temp.right;
            } else {
                father.right = temp.right;
            }
            
            if (parent.left == node) {
                parent.left = temp;
            } else {
                parent.right = temp;
            }
            
            temp.left = node.left;
            temp.right = node.right;
        }
    }
}