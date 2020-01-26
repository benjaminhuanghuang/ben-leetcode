/*
331. Verify Preorder Serialization of a Binary Tree [google电面]

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/
using System;
using System.Collections.Generic;

public class Solution331 {
    // 不断的砍掉叶子节点。最后看看能不能全部砍掉。
    // ”9,3,4,#,#,1,#,#,2,#,6,#,#” 遇到x # #的时候，就把它变为 #
    public bool IsValidSerialization(string preorder) {
        string[] nodes = preorder.Split(',');
        var stack = new List<string>();
        
        foreach (var node in nodes)
        {
            stack.Add(node);
            while(stack.Count >=3 && stack[stack.Count - 1] == "#" 
                                  && stack[stack.Count - 2] == "#"
                                  && stack[stack.Count - 3] != "#")
            {
                stack.RemoveRange(stack.Count-3, 2);
            }
        }
        return stack.Count == 1 && stack[0] == "#";
    }
}