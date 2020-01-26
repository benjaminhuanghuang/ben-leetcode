package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.LinkedList;
import java.util.Stack;

/*
449. Serialize and Deserialize BST  [297]
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later
in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be
serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

 */
public class LC_0449_SerializeandDeserializeBST {
    public class Codec {
        // Level Order Traversal
        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {
            if(root==null){
                return "";
            }

            StringBuilder sb = new StringBuilder();

            LinkedList<TreeNode> queue = new LinkedList<TreeNode>();

            queue.add(root);
            while(!queue.isEmpty()){
                TreeNode t = queue.poll();
                if(t!=null){
                    sb.append(String.valueOf(t.val) + ",");
                    queue.add(t.left);
                    queue.add(t.right);
                }else{
                    sb.append("#,");
                }
            }

            sb.deleteCharAt(sb.length()-1);
//            System.out.println(sb.toString());
            return sb.toString();
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize(String data) {
            if(data==null || data.length()==0)
                return null;

            String[] arr = data.split(",");
            TreeNode root = new TreeNode(Integer.parseInt(arr[0]));


            LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
            queue.add(root);

            int i=1;
            while(!queue.isEmpty()){
                TreeNode t = queue.poll();

                if(t==null)
                    continue;

                if(!arr[i].equals("#")){
                    t.left = new TreeNode(Integer.parseInt(arr[i]));
                    queue.offer(t.left);

                }else{
                    t.left = null;
                    queue.offer(null);
                }
                i++;

                if(!arr[i].equals("#")){
                    t.right = new TreeNode(Integer.parseInt(arr[i]));
                    queue.offer(t.right);

                }else{
                    t.right = null;
                    queue.offer(null);
                }
                i++;
            }

            return root;
        }

        public String serialize_preorder(TreeNode root) {
            if(root==null)
                return null;

            Stack<TreeNode> stack = new Stack<TreeNode>();
            stack.push(root);
            StringBuilder sb = new StringBuilder();

            while(!stack.isEmpty()){
                TreeNode h = stack.pop();
                if(h!=null){
                    sb.append(h.val+",");
                    stack.push(h.right);
                    stack.push(h.left);
                }else{
                    sb.append("#,");
                }
            }

            return sb.toString().substring(0, sb.length()-1);
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize_preorder(String data) {
            if(data == null)
                return null;

            int[] t = {0};
            String[] arr = data.split(",");

            return helper(arr, t);
        }

        public TreeNode helper(String[] arr, int[] t){
            if(arr[t[0]].equals("#")){
                return null;
            }

            TreeNode root = new TreeNode(Integer.parseInt(arr[t[0]]));

            t[0]=t[0]+1;
            root.left = helper(arr, t);
            t[0]=t[0]+1;
            root.right = helper(arr, t);

            return root;
        }
    }
}
