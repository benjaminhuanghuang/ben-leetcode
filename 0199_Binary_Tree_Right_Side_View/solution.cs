/*
199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/
using System.Linq;
using System.Collections.Generic;

public class Solution199 {
    public IList<int> RightSideView(TreeNode root) {
        List<int> res = new List<int>();
        if (root == null)
            return res;

        List<TreeNode> currLevel = new List<TreeNode>();
        currLevel.Add(root);

        while(currLevel.Count > 0)
        {   
            res.Add(currLevel[currLevel.Count-1].val);
            List<TreeNode> nextLevel = new List<TreeNode>();
            foreach (var node in currLevel)
            {
                if (node.left != null)
                    nextLevel.Add(node.left);
                if (node.right !=null )
                    nextLevel.Add(node.right);
            }
            currLevel = nextLevel;
        } 
        return res;
    }

    public IList<int> RightSideView_2(TreeNode root)
    {
        var res = new List<int>();
        var preQueue = new Queue<TreeNode>();
        if(root != null)
            preQueue.Enqueue(root);
        var curQueue = new Queue<TreeNode>();
        while (preQueue.Any())
        {
            res.Add(preQueue.Peek().val);
            while (preQueue.Any())
            {
                var top = preQueue.Dequeue();
                if (top.right != null) curQueue.Enqueue(top.right);
                if (top.left != null) curQueue.Enqueue(top.left);
            }

            while (curQueue.Any())
            {
                preQueue.Enqueue(curQueue.Dequeue());
            }
        }

        return res;
    }
}