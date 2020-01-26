package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
655. Print Binary Tree

Print a binary tree in an m*n 2D string array following these rules:

    The row number m should be equal to the height of the given binary tree.
    The column number n should always be an odd number.
    The root node's value (in string format) should be put in the exactly middle of the first row it can be put.
    The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
    Each unused space should contain an empty string "".
    Print the subtrees following the same rules.

Example 1:

Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]

 */


/*
设树的总深度为height，则二维数组宽度width = (1 << height) - 1

根节点的位置offset = width >> 1，深度depth = 1

左子树根的位置为offset - (1 + width >> depth + 1)

右子树根的位置为offset + (1 + width >> depth + 1)
 */
public class LC_0655_PrintBinaryTree {
    public List<List<String>> printTree(TreeNode root) {
        List<List<String>> res = new LinkedList<>();
        int height = root == null ? 1 : getHeight(root);
        int rows = height, columns = (int) (Math.pow(2, height) - 1);
        List<String> row = new ArrayList<>();
        // fill res with ""
        for (int i = 0; i < columns; i++) row.add("");
        for (int i = 0; i < rows; i++) res.add(new ArrayList<>(row));
        //
        populateRes(root, res, 0, rows, 0, columns - 1);
        return res;
    }

    public void populateRes(TreeNode root, List<List<String>> res, int row, int totalRows, int start, int end) {
        if (row == totalRows || root == null)
            return;
        res.get(row).set((start + end) / 2, Integer.toString(root.val));

        populateRes(root.left, res, row + 1, totalRows, start, (start + end) / 2 - 1);
        populateRes(root.right, res, row + 1, totalRows, (start + end) / 2 + 1, end);
    }

    public int getHeight(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(getHeight(root.left), getHeight(root.right));
    }

}
