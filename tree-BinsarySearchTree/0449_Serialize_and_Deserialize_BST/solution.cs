/*
449. Serialize and Deserialize BST

Serialization is the process of converting a data structure or object into a sequence of bits so that it 
can be stored in a file or memory buffer, or transmitted across a network connection link to be 
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary search tree 
can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize 
algorithms should be stateless.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Codec449 {
    // http://www.programcreek.com/2014/05/leetcode-serialize-and-deserialize-binary-tree-java/
    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        return "";
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        return null;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));