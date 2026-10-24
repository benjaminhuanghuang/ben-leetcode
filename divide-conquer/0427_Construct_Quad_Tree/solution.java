package cn.huang.leetcode;
/*
    427. Construct Quad Tree
 */
public class LC_0427_ConstructQuadTree {
    // Definition for a QuadTree node.
    class Node {
        public boolean val;
        public boolean isLeaf;
        public Node topLeft;
        public Node topRight;
        public Node bottomLeft;
        public Node bottomRight;

        public Node() {}

        public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
    };
    //如果一个正方形中所有的数字都是0，则val是False，否则val是True。
    // http://www.cnblogs.com/grandyang/p/9649348.html
    public Node construct(int[][] grid) {
        return helper(grid, 0, 0, grid.length);
    }

    Node helper(int[][] g, int i, int j, int len) {
        if(len == 1) return
                new Node(g[i][j] == 1, true, null, null, null, null);

        int nxt_len = len >> 1;
        Node tl = helper(g, i, j, nxt_len);
        Node tr = helper(g, i, j + nxt_len, nxt_len);
        Node bl = helper(g, i + nxt_len, j, nxt_len);
        Node br = helper(g, i + nxt_len, j + nxt_len, nxt_len);

        if(tl.isLeaf && tr.isLeaf && bl.isLeaf && br.isLeaf &&
                (tl.val && tr.val && bl.val && br.val || !tl.val && !tr.val && !bl.val && !br.val))
            return new Node(tl.val, true, null, null, null, null);
        else
            return new Node(false, false, tl, tr, bl, br);
    }
}
