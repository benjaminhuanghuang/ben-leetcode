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