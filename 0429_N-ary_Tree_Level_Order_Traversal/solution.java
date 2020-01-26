package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
429.
N-ary Tree Level Order Traversal
 */
public class LC_0429_NaryTreeLevelOrderTraversal {
    class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }

    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<>();

        if (root == null)
            return res;

        List<Node> layer = new ArrayList<>();
        layer.add(root);
        while (layer.size() > 0) {
            List<Integer> values = new ArrayList<>();
            List<Node> nextLayer = new ArrayList<>();
            for (Node n : layer) {
                values.add(n.val);
                for (Node c : n.children) {
                    nextLayer.add(c);
                }
            }
            res.add(values);
            layer = nextLayer;
        }
        return res;
    }
}
