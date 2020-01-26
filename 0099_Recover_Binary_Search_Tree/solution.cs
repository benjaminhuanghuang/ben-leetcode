/*
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a 
constant space solution?
*/
using System.Collections.Generic;

public class Solution099 {
    // O(N) space
    public void RecoverTree_On(TreeNode root) {
        List<TreeNode> nodeList = new List<TreeNode>();
        List<int> valList = new List<int>();
        this.Inorder(root, nodeList, valList);
        valList.Sort();
        for(int i = 0; i < valList.Count; i++)
        {
            nodeList[i].val = valList[i];
        }
    }

    private void Inorder(TreeNode root, List<TreeNode> nodeList, List<int> valList)
    {
        if (root!=null)
        {
            this.Inorder(root.left, nodeList, valList);
            nodeList.Add(root);
            valList.Add(root.val);
            this.Inorder(root.right, nodeList, valList);
        }
    }

    private TreeNode n1 = null;
    private TreeNode n2 = null;
    private TreeNode prev = null;
    public void RecoverTree(TreeNode root) {
        this.FindTwoNodes(root);
        int tmp = this.n1.val;
        this.n1.val = this.n2.val;
        this.n2.val = tmp;
    }
    // first violate node is the node which value is large than its next’s, 
    // while second node is the node which value is less than its previous node.
    private void FindTwoNodes(TreeNode root)
    {
        if (root != null)
        {
            this.FindTwoNodes(root.left);
            if(this.prev != null)
            {
                if (n1 == null && this.prev.val > root.val)
                {
                    this.n1 = this.prev;
                }
                if(n1 != null && this.prev.val > root.val)
                {
                    this.n2 = root;
                }
            }
            this.prev = root;
            this.FindTwoNodes(root.right);
        }
    }

}