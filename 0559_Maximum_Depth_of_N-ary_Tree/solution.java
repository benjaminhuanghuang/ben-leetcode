package cn.huang.leetcode;

import java.util.List;

/*
    559. Maximum Depth of N-ary Tree
 */
public class LC_0559_MaximumDepthofNaryTree {
    class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val,List<Node> _children) {
            val = _val;
            children = _children;
        }
    };


    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }

        int max = 0;
        for (Node child : root.children) { //replace left&right to for loop
            int value = maxDepth(child);

            if (value > max) {
                max = value;
            }
        }
        return max +1;
    }
}
