/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to 
adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

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
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution120 {

    // https://shenjie1993.gitbooks.io/leetcode-python/content/120%20Triangle.html
    // dp[j] = min(dp[j+1], dp[j]) + triangle[i][j].
    public int MinimumTotal(IList<IList<int>> triangle) 
    {   
        if (triangle.Count == 0)
        {
            return 0;
        }
        var dp = triangle[triangle.Count-1].ToArray();
        
        for (int row = triangle.Count - 2; row >=0 ; row--)
        {   for (int col = 0; col <= row; col++)
            {
                dp[col] = Math.Min(dp[col], dp[col+1]) + triangle[row][col];
            }
        }
        return dp[0];
    }
    // dp[i][j] = min(dp[i – 1][j], dp[i][j]) + triangle[i][j].
    public int MinimumTotal_2(IList<IList<int>> triangle) 
    {
        if (triangle.Count == 0)
        {
            return 0;
        }
        var mimimumPath = int.MaxValue;
        var dp = new int[triangle.Count];
        for (var i = 0; i < dp.Length; i++)
        {
            dp[i] = int.MaxValue;
        }

        dp[0] = triangle[0][0];
        for (int row = 1; row < triangle.Count; row++)
        {   for (int col = 0; col <= row; col++)
            {
                if (col == 0)
                {
                    dp[col] = dp[col] + triangle[row][col];
                }
                else
                {
                    dp[col] = Math.Min(dp[col - 1], dp[col]) + triangle[row][col];
                }
            }
        }
        

        foreach (var path in dp)
        {
            if (path < mimimumPath)
            {
                mimimumPath = path;
            }
        }

        return mimimumPath;
    }

    //  Brute force solution use recursion.
    private int minimumPath = int.MaxValue;
    public int minimumTotal(List<List<int>> triangle)
    {
        this.minimumTotalRecursion(triangle, 0, 0, 0);

        return minimumPath;
    }

    public void minimumTotalRecursion(List<List<int>> triangle, int layer, int index, int currentSum)
    {
        if (layer == triangle.Count)
        {
            if (currentSum < minimumPath)
            {
                minimumPath = currentSum;
            }

            return;
        }

        if (layer == 0)
        {
            this.minimumTotalRecursion(triangle, layer + 1, index, currentSum + triangle[layer][index]);
        }
        else
        {
            this.minimumTotalRecursion(triangle, layer + 1, index, currentSum + triangle[layer][index]);
            this.minimumTotalRecursion(triangle, layer + 1, index + 1, currentSum + triangle[layer][index + 1]);
        }
    }
}