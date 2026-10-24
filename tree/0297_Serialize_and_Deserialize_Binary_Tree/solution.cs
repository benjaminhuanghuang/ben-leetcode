using System.Text;
using System.Collections.Generic;

//  pre-order traversal + recursion
public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        if (root == null) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        serializeHelper(root, sb);
        return "["+sb.ToString()+"]";
    }

    private void serializeHelper(TreeNode node, StringBuilder sb)
    {
        if (node != null)
        {
            sb.Append(node.val+",");
            serializeHelper(node.left, sb);
            serializeHelper(node.right, sb);
        }
        else
            sb.Append("#,");
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if (data == "[]") {
            return null;
        }
        List<string> vals = new List<string>(data.Substring(1, data.Length - 2).Split(','));
        TreeNode root = deserializeHelper(vals);
        return root;
    }

    private TreeNode deserializeHelper(List<string> vals)
    {   
        if (vals.Count == 0)
            return null;
        string v = vals[0];
        vals.RemoveAt(0);
        if (v == "#")
            return null;
        TreeNode node = new TreeNode(int.Parse(v));
        node.left = deserializeHelper(vals);
        node.right = deserializeHelper(vals);
        return node;
    }
}

//层序遍历的非递归解法
public class Codec_2 {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
         if (root == null) {
            return "[]";
        }

        List<TreeNode> queue = new List<TreeNode>();
        queue.Add(root);

        for (int i = 0; i < queue.Count; i++) {
            TreeNode node = queue[i];
            if (node == null) {
                continue;
            }
            queue.Add(node.left);
            queue.Add(node.right);
        }

        while (queue[queue.Count - 1] == null) {
            queue.RemoveAt(queue.Count - 1);
        }

        StringBuilder sb = new StringBuilder();
        sb.Append("[");
        sb.Append(queue[0].val);
        for (int i = 1; i < queue.Count; i++) {
            if (queue[i] == null) {
                sb.Append(",#");
            } else {
                sb.Append(",");
                sb.Append(queue[i].val);
            }
        }
        sb.Append("]");
        return sb.ToString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if (data == "[]") {
            return null;
        }
        string[] vals = data.Substring(1, data.Length - 2).Split(',');
        List<TreeNode> queue = new List<TreeNode>();
        TreeNode root = new TreeNode(int.Parse(vals[0]));
        queue.Add(root);
        int index = 0;
        bool isLeftChild = true;
        for (int i = 1; i < vals.Length; i++) {
            if (vals[i]!="#") {
                TreeNode node = new TreeNode(int.Parse(vals[i]));
                if (isLeftChild) {
                    queue[index].left = node;
                } else {
                    queue[index].right = node;
                }
                queue.Add(node);
            }
            if (!isLeftChild) {
                index++;
            }
            isLeftChild = !isLeftChild;
        }
        return root;
    }
}

/*
 var input = "[1]";

        var s = new Codec();
        var result = s.deserialize(input);  

        Console.WriteLine(result);

    var root = codec.deserialize(codec.serialize(root));

*/