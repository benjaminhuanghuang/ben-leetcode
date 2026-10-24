package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.*;

/*

919. Complete Binary Tree Inserter

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

    CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;

    CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete,
        and returns the value of the parent of the inserted TreeNode;

    CBTInserter.get_root() will return the head node of the tree.
 */
public class LC_0919_CompleteBinaryTreeInserter {
    /*
    http://massivealgorithms.blogspot.com/2018/11/leetcode-919-complete-binary-tree.html

     Consider all the nodes numbered first by level and then left to right. Call this the "number order" of the nodes.
    At each insertion step, we want to insert into the node with the lowest number (that still has 0 or 1 children).
    By maintaining a deque (double ended queue) of these nodes in number order, we can solve the problem. After inserting
    a node, that node now has the highest number and no children, so it goes at the end of the deque.
    To get the node with the lowest number, we pop from the beginning of the deque.
    Algorithm
    First, perform a breadth-first search to populate the deque with nodes that have 0 or 1 children, in number order.
    Now when inserting a node, the parent is the first element of deque, and we add this new node to our deque.
     */
    class CBTInserter {
        TreeNode root;
        Deque<TreeNode> deque;

        public CBTInserter(TreeNode root) {
            this.root = root;
            deque = new LinkedList();
            Queue<TreeNode> queue = new LinkedList();
            queue.offer(root);  // push

            // 构建树的时候使用层次遍历，也就是BFS把所有的节点放入到tree里。
            // BFS to populate deque
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                if (node.left == null || node.right == null)
                    deque.offerLast(node);
                if (node.left != null)
                    queue.offer(node.left);
                if (node.right != null)
                    queue.offer(node.right);
            }
        }

        public int insert(int v) {
            TreeNode node = deque.peekFirst();
            deque.offerLast(new TreeNode(v));
            if (node.left == null)
                node.left = deque.peekLast();
            else {
                node.right = deque.peekLast();
                deque.pollFirst();
            }

            return node.val;
        }

        public TreeNode get_root() {
            return root;
        }
    }

    /*
     Store tree nodes to a list self.tree in bfs order.
    Node tree[i] has left child tree[2 * i + 1] and tree[2 * i + 2]


    So when insert the Nth node (0-indexed), we push it into the list.
    we can find its parent tree[(N - 1) / 2] directly.
     */
    class CBTInserter2 {
        List<TreeNode> tree;
        public CBTInserter2(TreeNode root) {
            tree = new ArrayList<>();
            tree.add(root);
            for (int i = 0; i < tree.size(); ++i) {
                if (tree.get(i).left != null) tree.add(tree.get(i).left);
                if (tree.get(i).right != null) tree.add(tree.get(i).right);
            }
        }

        public int insert(int v) {
            int N = tree.size();
            TreeNode node = new TreeNode(v);
            tree.add(node);
            if (N % 2 == 1)
                tree.get((N - 1) / 2).left = node;
            else
                tree.get((N - 1) / 2).right = node;
            return tree.get((N - 1) / 2).val;
        }

        public TreeNode get_root() {
            return tree.get(0);
        }
    }
}
