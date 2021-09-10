/*
1302. Deepest Leaves Sum

Level: Medium

https://leetcode.com/problems/deepest-leaves-sum
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
/*
  Solution: 
*/
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
class Solution {
    int maxLevel, maxVal;

    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 0);
        return maxVal;
    }

    void dfs(TreeNode root, int level){
        if(root == null){
            return;
        }

        if(root.left == null && root.right == null){
            // leaf node
            if(level > maxLevel){
                // deepest level
                maxVal = root.val;
                maxLevel = level;
            }else if(level == maxLevel) {
                maxLevel += root.level;
            }
            return;
        }
        dfs(root.left, level + 1);
        dfs(root.right, level + 1);
    }
}