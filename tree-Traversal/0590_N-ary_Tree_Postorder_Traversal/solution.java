package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

/*
    590. N-ary Tree Postorder Traversal
 */
public class LC_0590_NaryTreePostorderTraversal {
    class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val,List<Node> _children) {
            val = _val;
            children = _children;
        }
    };
    public List<Integer> postorder_Recursive(Node root) {
        List<Integer> res = new ArrayList<>();
        postorder_helper(root, res);

        return res;
    }
    private void postorder_helper(Node root, List<Integer> res){
        if(root == null)
            return;

        for(Node n: root.children){
            postorder_helper(n, res);
        }

        res.add(root.val);
    }

    public List<Integer> postorder_Iterative(Node root) {
        List<Integer> res = new ArrayList<>();
        if(root == null)
            return res;

        Stack<Node> s = new Stack<>();
        s.push(root);
        while (!s.isEmpty())
        {
            Node n = s.pop();
            res.add(n.val);
            for(Node c: n.children){
                s.push(c);
            }
        }
        Collections.reverse(res);
        return res;
    }
}
