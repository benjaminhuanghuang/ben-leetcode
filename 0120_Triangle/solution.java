package cn.huang.leetcode;

import java.util.List;

/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

 */
public class LC_0120_Triangle {
    /*
     dp[j] = min(dp[j+1], dp[j]) + triangle[i][j].
     Take
     [[2],
      [3,4],
      [5,6,7]]
      as a sample, to cell [3], dp value should be 3 + min(5,6)
     */
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        int rows = triangle.size();
        int[] dp = new int[rows];

        for (int col = 0; col < rows; col++) {
            dp[col] = triangle.get(rows - 1).get(col);     // put value of last row into dp[]
        }

        for (int row = rows - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle.get(row).get(col) + Math.min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];
    }
}
