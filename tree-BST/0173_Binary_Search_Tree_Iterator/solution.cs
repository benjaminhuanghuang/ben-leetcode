/*
173. Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the 
root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height 
of the tree.
*/
using System.Collections.Generic;

public class BSTIterator {
    private readonly Stack<TreeNode> _mystack = new Stack<TreeNode>(); 
    public BSTIterator(TreeNode root) {
        // initialize BST Tree, put its left node into stack until the node does not have 
        // left node. So the top one in stack is smallest node in the tree.
        findMostLeftNode(root, _mystack);
    }

    /** @return whether we have a next smallest number */
    public bool HasNext() {
        return _mystack.Count > 0;
    }

    /** @return the next smallest number */
    public int Next() {
        TreeNode top = _mystack.Pop();
        findMostLeftNode(top.right, _mystack);

        return top.val;
    }
    private void findMostLeftNode(TreeNode root, Stack<TreeNode> mystack)
    {
        while (root != null)
        {
            mystack.Push(root);
            root = root.left;
        }
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.HasNext()) v[f()] = i.Next();
 */