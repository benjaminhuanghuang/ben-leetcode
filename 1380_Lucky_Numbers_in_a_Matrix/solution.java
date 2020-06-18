/*
1380. Lucky Numbers in a Matrix

Level: Easy

https://leetcode.com/problems/lucky-numbers-in-a-matrix
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
/*
  Solution: 
*/
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
      int m = matrix.length, n = matrix[0].length;
      int[] minRow = new int[m], maxCol = new int[n];
      Arrays.fill(mi, Integer.MAX_VALUE);
      for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
              minRow[i] = Math.min(matrix[i][j], mi[i]);
              maxCol[j] = Math.max(matrix[i][j], mx[j]);
          }
      }
      List<Integer> res = new ArrayList<>();
      for (int i = 0; i < m; ++i)
          for (int j = 0; j < n; ++j)
              if (minRow[i] == maxCol[j]) 
                  res.add(mi[i]);
      return res;  
    }
}