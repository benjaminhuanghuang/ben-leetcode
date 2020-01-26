package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
222. Count Complete Tree Nodes

Given a complete binary tree, moves the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last
level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6


 */
/*
完全二叉树 (Complete Binary Tree)：

A Complete Binary Tree （CBT) is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

对于一颗二叉树，假设其深度为d（d>1）。除了第d层外，其它各层的节点数目均已达最大值，且第d层所有节点从左向右连续地紧密排列，这样的二叉树被称为完全二叉树；

换句话说，完全二叉树从根结点到倒数第二层满足完美二叉树，最后一层可以不完全填充，其叶子结点都靠左对齐。

完美二叉树 (Perfect Binary Tree)：

A Perfect Binary Tree(PBT) is a tree with all leaf nodes at the same depth. All internal nodes have degree 2.

二叉树的第i层至多拥有2^{i-1}个节点数；深度为k的二叉树至多总共有2^{k+1}-1个节点数，而总计拥有节点数匹配的，称为“满二叉树”；

完满二叉树 (Full Binary Tree):

A Full Binary Tree (FBT) is a tree in which every node other than the leaves has two children.

换句话说，所有非叶子结点的度都是2。（只要你有孩子，你就必然是有两个孩子。）

完美二叉树一定是完全二叉树，而完全二叉树不一定是完美二叉树。
完全二叉树就有可能是完美二叉树，若是完美二叉树，节点个数很好求，为2的h次方-1，h为该完美二叉树的高度。


 在一棵完全二叉树的每一层，除最后一层外，其余各层都是填满的，并且最后一层的节点尽可能的靠左排列。
 最后一层（第h层）包含的节点个数介于[1, 2^h]区间之内。

 */
public class LC_0222_CountCompleteTreeNodes {
    public int countNodes(TreeNode root) {
        if(root == null)
            return 0;
        int count = 1;
        if (root.left != null)
            count += countNodes(root.left);
        if (root.right != null)
            count += countNodes(root.right);

        return count;
    }
}
