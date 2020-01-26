package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.*;

/*
987. Vertical Order Traversal of a Binary Tree [314]

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes,
we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.



Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.


Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.
 */
public class LC_0987_VerticalOrderTraversalofaBinaryTree {
    /*
        https://zxi.mytechroad.com/blog/2019/02/
     */
    List<int[]> ret = new ArrayList<>();

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        // root node is at position (0, 0):
        check(root, 0, 0);
        // sort by x, y , val
        Collections.sort(ret, (a, b) -> (a[0] != b[0] ? a[0] - b[0] : a[1] != b[1] ? a[1] - b[1] : a[2] - b[2]));
        List<List<Integer>> ans = new ArrayList<>();
        int preX = -1000000;
        List<Integer> list = null;
        for (int[] x : ret) {
            if (x[0] != preX) {
                preX = x[0];
                list = new ArrayList<>();
                ans.add(list);
            }
            list.add(x[2]);
        }
        return ans;
    }

    private void check(TreeNode node, int x, int y) {
        if (node == null)
            return;
        ret.add(new int[]{x, y, node.val});
        check(node.left, x - 1, y + 1); // y+1, not y-1 here
        check(node.right, x + 1, y + 1);
    }
}