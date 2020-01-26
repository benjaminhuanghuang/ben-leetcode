package cn.huang.leetcode;

/*
174. Dungeon Game
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in
the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops
to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each
step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal
path RIGHT-> RIGHT -> DOWN -> DOWN.


Note:

    The knight's health has no upper bound.
    Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room
    where the princess is imprisoned.


 */

/*
http://zhuixin8.com/2016/10/02/leetcode-174/
骑士从坐标(i+1,j)出发到达公主所在的房间所需要的最少血量，dp[i+1][j]；
骑士从坐标(i,j+1)出发到达公主所在的房间所需要的最少血量，dp[i][j+1]；
坐标(i,j)所在的房间中包含的补给或威胁对应的数值，dungeon[i][j]。

动态规划转移方程:

dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])−dungeon[i][j])

其中，min(dp[i+1][j],dp[i][j+1])表示从向右或者向下的道路中选择所需血量较少的那一条路前进，因为房间中可能有怪物或者补给，所以得到的值需要减去这个房间中补给或怪物对应的数值dungeon[i][j]，又因为骑士的血量不能低于1，因此还需要执行max函数来保证dp[i][j]大于等于1。

index从0开始，最终要在(m-1, n-1)的位置有1个hp。那么按照题目的逻辑，从(m-1, n-1)能继续下去，在(m, n-1)和(m-1,n)都要至少要为1. 然后一步步朝左上角返回上去。


 */
public class LC_0174_DungeonGame {
    public int calculateMinimumHP(int[][] dungeon) {
        if (dungeon == null || dungeon.length == 0) {
            return 1;
        }

        int rows = dungeon.length;
        int cols = dungeon[0].length;
        int[][] miniHP = new int[rows][cols];
        miniHP[rows - 1][cols - 1] = Math.max(1, 1 - dungeon[rows - 1][cols - 1]);

        for (int i = rows - 2; i >= 0; i--) {
            miniHP[i][cols - 1] = Math.max(1, miniHP[i + 1][cols - 1] - dungeon[i][cols - 1]);
        }

        for (int j = cols - 2; j >= 0; j--) {
            miniHP[rows - 1][j] = Math.max(1, miniHP[rows - 1][j + 1] - dungeon[rows - 1][j]);
        }

        for (int i = rows - 2; i >= 0; i--) {
            for (int j = cols - 2; j >= 0; j--) {
                miniHP[i][j] = Math.max(1, Math.min(miniHP[i][j + 1], miniHP[i + 1][j]) - dungeon[i][j]);
            }
        }

        return miniHP[0][0];
    }
}
