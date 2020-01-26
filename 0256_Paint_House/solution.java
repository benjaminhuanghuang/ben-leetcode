package cn.huang.leetcode;
/*
256. Paint House

 There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.
 The cost of painting each house with a certain color is different. You have to paint all the houses such that
 no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
For example, costs[0][0] is the cost of painting house 0 with color red;
costs[1][2] is the cost of painting house 1 with color green, and so on...
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
 */

/*
    [房子][color]
 Thought process:

    Sub-problem: find the minimum cost to paint the houses up to current house in red, blue or green.
    Function:
        Red: min(f[i - 11][1], f[i - 1][2]) + costs[i][0].
        Blue: min(f[i - 1][0], f[i - 1][2]) + costs[i][1].
        Green: min(f[i - 1][0], f[i - 1][1]) + costs[i][2].
    Initialization: f[0][i] = 0.
    Answer: min(f[costs.length][i]).

 */
public class LC_0256_PaintHouse {
    public int minCost(int[][] costs) {
        if (costs.length == 0) {
            return 0;
        }

        for (int i = 1; i < costs.length; i++) {
            costs[i][0] += Math.min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += Math.min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += Math.min(costs[i - 1][0], costs[i - 1][1]);
        }

        int last = costs.length - 1;
        return Math.min(costs[last][0], Math.min(costs[last][1], costs[last][2]));
    }

    public int minCost2(int[][] costs) {
        if (costs == null || costs.length == 0 || costs[0].length == 0) {
            return 0;
        }

        int house = costs.length, color = costs[0].length;
        int[][] f = new int[house][color];
        //Initialize
        f[0][0] = costs[0][0];
        f[0][1] = costs[0][1];
        f[0][2] = costs[0][2];
        //Function
        for (int i = 1; i < house; i++) {
            f[i][0] = Math.min(f[i - 1][1], f[i - 1][2]) + costs[i][0];
            f[i][1] = Math.min(f[i - 1][0], f[i - 1][2]) + costs[i][1];
            f[i][2] = Math.min(f[i - 1][0], f[i - 1][1]) + costs[i][2];
        }

        return Math.min(f[house - 1][0], Math.min(f[house - 1][1], f[house - 1][2]));
    }
}
