package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/*
988. Smallest String Starting From Leaf

Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z':
a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically
smaller than "aba".  A leaf of a node is a node that has no children.)



Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:



Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:



Input: [2,2,1,null,1,0,null,0]
Output: "abc"


Note:

The number of nodes in the given tree will be between 1 and 1000.
Each node in the tree will have a value between 0 and 25.
 */
public class LC_0988_SmallestStringStartingFromLeaf {

    public String smallestFromLeaf(TreeNode root) {
        List<String> words = new ArrayList<>();
        if (root == null)
            return "";
        addWords(root, "", words);

        Collections.sort(words);
        if (words.size() > 0)
            return words.get(0);
        return "";
    }

    private void addWords(TreeNode node, String str, List<String> words) {
        String newStr = str + String.valueOf((char) (node.val + 'a'));
        if (node.left == null && node.right == null) {
            words.add(new StringBuilder(newStr).reverse().toString());
            return;
        }

        if (node.left != null)
            addWords(node.left, newStr, words);
        if (node.right != null)
            addWords(node.right, newStr, words);
    }

    /*
    https://zxi.mytechroad.com/blog/2019/02/
    Time complexity: O(n^2)
    Space complexity: O(n^2)
     */
    public String smallestFromLeaf_hua(TreeNode root) {
        List<String> words = new ArrayList<>();
        if (root == null)
            return "";
        char v = (char) ('a' + root.val);

        String l = smallestFromLeaf(root.left);
        String r = smallestFromLeaf(root.right);
        if (l.length() == 0)
            return r + v;
        if (r.length() == 0)
            return l + v;
        return (l.compareTo(r) > 0 ? r : l) + v;
    }
}
