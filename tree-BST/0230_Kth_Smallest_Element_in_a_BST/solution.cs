/*
230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest 
frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).

*/

using System.Collections.Generic;

public class Solution230 {
    public int KthSmallest(TreeNode root, int k) {
        var stack = new Stack<TreeNode>();
        var node = root;

        while(node != null)
        {
            stack.Push(node);
            node = node.left;
        }        
        int x = 1;
        while(stack.Count > 0 && x <=k)
        {
            node = stack.Pop();
            x ++;
            var right = node.right;
            while (right != null)
            {
                stack.Push(right);
                right = right.left;
            }
        }
        return node.val;
    }
}