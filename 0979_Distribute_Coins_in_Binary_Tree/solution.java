package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
979. Distribute Coins in Binary Tree

Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.
(The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.



Example 1:

Input: [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:

Input: [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves].  Then, we move one coin from the root of the tree to the right child.

Example 3:

Input: [1,0,2]
Output: 2

Example 4:

Input: [1,0,0,null,3]
Output: 4



Note:

    1<= N <= 100
    0 <= node.val <= N


 */

/*
For the subtree rooted at node i, node i has to make the left subtree and right subtree satisfied.
So if left subtree has 3 coins more, it will give node i 3 coins;
If right subtree has 2 coins less, node i will give it 2 coins.
Now the whole subtree is satisfied except for node i.
And we will return back how many coins does node i need so it's parent will give/get the coins and make the whole subtree satisfied.

So for current root, we only cares how many coins does it's left child and right child need since the left subtree and
right subtree are already satisfied. (expect for left child and right child).

Time Complexity: O(N)
Space Complexity: O(1) or O(n) because of recusive stack space
 */
public class LC_0979_DistributeCoinsinBinaryTree {
    int moves = 0;

    public int distributeCoins(TreeNode root) {
        postorder(root);
        return moves;
    }

    int postorder(TreeNode node) {
        if (node == null) return 0;
        int left = postorder(node.left);
        int right = postorder(node.right);

        int x = node.val - 1 + left + right;
        moves += Math.abs(x);
        return x;
    }
}
