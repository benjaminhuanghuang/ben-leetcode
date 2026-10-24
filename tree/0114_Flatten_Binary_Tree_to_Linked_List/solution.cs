using System.Collections.Generic;

public class Solution114 {
    public void Flatten(TreeNode root) {
        var nodes = new List<TreeNode>();
        this.FlattenHelper(root, nodes);

        var start = root;
        for (int i = 1; i < nodes.Count; i++)
        {
            start.right = nodes[i];
            start.left = null;

            start = start.right;
        }
    }
    // pre-order
    private void FlattenHelper(TreeNode root, List<TreeNode> nodes)
    {
        if (root == null) return;
        // visited root
        nodes.Add(root);

        this.FlattenHelper(root.left, nodes);
        this.FlattenHelper(root.right, nodes);
    }
}