package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class LC_0589_NaryTreePreorderTraversal {
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

    ;

    public List<Integer> postorder_Recursive(Node root) {
        List<Integer> res = new ArrayList<>();
        preorder_helper(root, res);

        return res;
    }

    private void preorder_helper(Node root, List<Integer> res) {
        if (root == null)
            return;

        res.add(root.val);
        for (Node n : root.children) {
            preorder_helper(n, res);
        }
    }

    public List<Integer> preorder_Iterative(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        Stack<Node> s = new Stack<>();
        s.push(root);
        while (!s.empty()) {
            //栈顶元素出栈
            Node n = s.pop();
            res.add(n.val);
            //由于是 先序，所以让右节点先入栈, 左节点再入栈
            for (int i = n.children.size() - 1; i >= 0; i--) {
                s.push(n.children.get(i));
            }
        }
        return res;
    }
}
