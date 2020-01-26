package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

/*
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2

Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

Follow up:

    A solution using O(n) space is pretty straight forward.
    Could you devise a constant space solution?


 */
public class LC_0099_RecoverBinarySearchTree {
    // O(N) space
    public void RecoverTree_On(TreeNode root) {
        List<TreeNode> nodeList = new ArrayList<TreeNode>();
        List<Integer> valList = new ArrayList<Integer>();
        this.Inorder(root, nodeList, valList);
        Collections.sort(valList);
        for(int i = 0; i < valList.size(); i++)
        {
            nodeList.get(i).val = valList.get(i);
        }
    }

    private void Inorder(TreeNode root, List<TreeNode> nodeList, List<Integer> valList)
    {
        if (root!=null)
        {
            this.Inorder(root.left, nodeList, valList);
            nodeList.add(root);
            valList.add(root.val);
            this.Inorder(root.right, nodeList, valList);
        }
    }

    /*
    https://www.youtube.com/watch?v=2rsGbHnIDV0
     */
    TreeNode first = null;
    TreeNode second = null;
    TreeNode prev= null;

    public void recoverTree(TreeNode root)
    {
        if(root == null)
            return;
        helper(root);
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    public void helper(TreeNode root)
    {
        if(root == null)
            return;
        helper(root.left);

        //prev.val > root.val 表示出现错误
        if(prev != null && prev.val > root.val)
        {
            if(first == null)
                first = prev; // record the wrong node
            second = root;
        }
        prev = root;
        helper(root.right);
    }

    public void recoverTree2(TreeNode root)
    {
        if(root == null)
            return;
        TreeNode first = null;
        TreeNode second = null;
        TreeNode prev= null;

        TreeNode curr = root;
        Stack<TreeNode> stack = new Stack<>();

        while(!stack.isEmpty() || curr!=null)
        {
            if(curr!=null)
            {
                stack.push(curr);
                curr = curr.left;
            }
            else
            {
                curr = stack.pop();
                if(prev !=null && curr.val <=prev.val)
                {
                    if(first == null)
                        first = prev; // record the wrong node
                    second = curr;
                }
                prev = curr;
                curr = curr.right;
            }
        }
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
}
