package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.LinkedList;
import java.util.Stack;

/*
297. Serialize and Deserialize Binary Tree [449]

Serialization is the process of converting a data structure or object into a sequence of bits so that it can
be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later
in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized
to a string and this string can be deserialized to the original tree structure.

Example:

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to
follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


 */
public class LC_0297_SerializeandDeserializeBinaryTree {
    /*
    https://www.youtube.com/watch?v=JL4OjKV_pGE
    https://zxi.mytechroad.com/blog/tree/leetcode-297-serialize-and-deserialize-binary-tree/
     */
    public String serialize1(TreeNode root) {
        if (root == null) {
            return "#";
        }

        StringBuilder sb = new StringBuilder();

        write(root, sb);
        return sb.toString().substring(0, sb.length() - 1);
    }

    private int index = 0;
    // Decodes your encoded data to tree.
    public TreeNode deserialize1(String data) {
        if (data == null || data.length() == 0)
            return null;

        return read(data.split(" "));
    }

    private void write(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append("# ");
            return;
        }
        sb.append(node.val + " ");

        write(node.left, sb);
        write(node.right, sb);
    }

    private TreeNode read(String[] values) {
        String value = values[index];
        if (value.equals("#")) {
            index++;
            return null;
        }

        TreeNode root = new TreeNode(Integer.parseInt(value));
        index++;
        root.left = read(values);
        root.right = read(values);
        return root;
    }


    /*
     Level Order Traveral
     */
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "";
        }

        StringBuilder sb = new StringBuilder();

        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();

        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode t = queue.poll();
            if (t != null) {
                sb.append(String.valueOf(t.val) + ",");
                queue.add(t.left);
                queue.add(t.right);
            } else {
                sb.append("#,");
            }
        }

        sb.deleteCharAt(sb.length() - 1);
        System.out.println(sb.toString());
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0)
            return null;

        String[] arr = data.split(",");
        TreeNode root = new TreeNode(Integer.parseInt(arr[0]));


        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);

        int i = 1;
        while (!queue.isEmpty()) {
            TreeNode t = queue.poll();

            if (t == null)
                continue;

            if (!arr[i].equals("#")) {
                t.left = new TreeNode(Integer.parseInt(arr[i]));
                queue.offer(t.left);

            } else {
                t.left = null;
                queue.offer(null);
            }
            i++;

            if (!arr[i].equals("#")) {
                t.right = new TreeNode(Integer.parseInt(arr[i]));
                queue.offer(t.right);

            } else {
                t.right = null;
                queue.offer(null);
            }
            i++;
        }

        return root;
    }

    /*
    Solution 2 - Preorder Traversal
    */
    // Encodes a tree to a single string.
    public String serialize_Preorder(TreeNode root) {
        if (root == null)
            return null;

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
        StringBuilder sb = new StringBuilder();

        while (!stack.isEmpty()) {
            TreeNode h = stack.pop();
            if (h != null) {
                sb.append(h.val + ",");
                stack.push(h.right);
                stack.push(h.left);
            } else {
                sb.append("#,");
            }
        }

        return sb.toString().substring(0, sb.length() - 1);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize_Preorder(String data) {
        if (data == null)
            return null;

        int[] t = {0};
        String[] arr = data.split(",");

        return helper(arr, t);
    }

    public TreeNode helper(String[] arr, int[] t) {
        if (arr[t[0]].equals("#")) {
            return null;
        }

        TreeNode root = new TreeNode(Integer.parseInt(arr[t[0]]));

        t[0] = t[0] + 1;
        root.left = helper(arr, t);
        t[0] = t[0] + 1;
        root.right = helper(arr, t);

        return root;
    }
}
