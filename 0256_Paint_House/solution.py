# coding: utf-8
'''
256. Paint House

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two
adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix.

For example, costs[0][0] is the cost of painting house 0 with color red,
costs[1][2] is the cost of painting house 1 with color green,
and so on...

Find the minimum cost to paint all houses.

'''

'''
http://www.cnblogs.com/Dylan-Java-NYC/p/5327630.html
类似House Robber. red = 当前房子paint red cost + Math.min(之前paint blue的总花费，之前paint green的总花费). blue 和 green 同理.

http://blog.csdn.net/qq508618087/article/details/50871604
思路: 每个房子有三种染色方案, 那么如果当前房子染红色的话, 最小代价将是上一个房子的绿色和蓝色的最小代价+当前房子染红色的代价.
对另外两种颜色也是如此. 因此动态转移方程为:

             dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i-1][0];

             dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i-1][1];

             dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i-1][2];

http://www.dongcoder.com/detail-18448.html
http://www.cnblogs.com/grandyang/p/5319384.html
'''


class Solution(object):
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if len(costs) == 0:
            return 0
        dp = [[0 for i in range(3)] for j in range(len(costs))]
        dp[0][0] = costs[0][0]  # red
        dp[0][1] = costs[0][1]  # blue
        dp[0][2] = costs[0][2]  # green
        i = 1
        while i < len(costs):
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]
            i += 1
        return min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]))
