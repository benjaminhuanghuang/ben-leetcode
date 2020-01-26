package cn.huang.leetcode;
/*
272. Closest Binary Search Tree Value II

Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:

Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.

 */


import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

/*
思路: 利用二叉搜索树的中序遍历, 如果结果集合中元素还不到k个, 就把当前元素加到集合中去, 如果集合中的元素个数多于k了, 那么有二种情况:

1. target的值比集合中最小的值小, 因为中序遍历是有序的, 最小元素就是第0个元素

2. target的值大于结果集合中的最小值, 小于最大值

3. target的值大于集合中的最大值

当集合中的元素个数大于k的时候, 我们需要进行元素替换. 

如果是第一种情况, 那么将无法进行替换, 因为第0个元素就是最靠近的值, 并且在集合中元素是有序的, 因此此时集合中就是最靠近的k个元素.

如果是第二三种情况, 那么我们比较当前值和集合中最小值, 如果当前结点值比那个值更靠近target, 那么我们就用当前元素替换最小的值

直到我们无法再找到能够替换的元素, 就可以返回结果了.
 */
public class LC_0272_ClosestBinarySearchTreeValue_II {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> res = new ArrayList<Integer>();

        Deque<Integer> pre = new LinkedList<Integer>();
        Deque<Integer> suc = new LinkedList<Integer>();

        inorder(root, target, false, pre);
        inorder(root, target, true, suc);

        while (k-- > 0) {
            if (pre.isEmpty())
                res.add(suc.pop());
            else if (suc.isEmpty())
                res.add(pre.pop());
            else if (Math.abs(suc.peek() - target) < Math.abs(pre.peek() - target))
                res.add(suc.pop());
            else
                res.add(pre.pop());
        }

        return res;

    }

    private void inorder(TreeNode node, double target, boolean reverse, Deque<Integer> stack) {
        if (node == null) return;

        inorder(reverse ? node.right : node.left, target, reverse, stack);
        if ((reverse && node.val <= target) || (!reverse && node.val > target)) return;
        stack.push(node.val);
        inorder(reverse ? node.left : node.right, target, reverse, stack);
    }
}
