package cn.huang.leetcode;

/*
913. Cat and Mouse

A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.
For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:

    If ever the Cat occupies the same node as the Mouse, the Cat wins.
    If ever the Mouse reaches the Hole, the Mouse wins.
    If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same
    player's turn to move), the game is a draw.

Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by
Cat, and 0 if the game is a draw.



Example 1:

Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Explanation:
4---3---1
|   |
2---5
 \ /
  0



Note:

    3 <= graph.length <= 50
    It is guaranteed that graph[1] is non-empty.
    It is guaranteed that graph[2] contains a non-zero element.


 */

import java.util.Arrays;

/*
有一张无向图，包含最多50个结点。有两个玩家（Mouse和Cat）在图上，Mouse的起始位置是1，Cat的起始位置是2，0处有一个洞，
Cat不能移动到0。Mouse和Cat在图上轮流移动，每次必须移动到与当前结点相邻的一个结点。

游戏有三种结束的可能：

    Cat和Mouse进入同一结点，则Cat胜利
    Mouse进入0结点，则Mouse胜利
    Cat和Mouse的位置和回合发生了重复，则平局

问：如果Cat和Mouse都以最优策略行动，最后的结果是什么？
 */
public class LC_0913_CatandMouse {
    public int catMouseGame(int[][] graph) {
        int size = graph.length;
        int dp[][] = new int[size][size];
        for (int i = 0; i < size; i++)
            Arrays.fill(dp[i], -1);  // unvisited

        for (int i = 1; i < size; ++i) {
            dp[0][i] = 1;   // mouse reached home, m win
            dp[i][i] = 2;   // cat met mouse, cat win
        }

        return helper(graph, 1, 2, dp);
    }

    public int helper(int[][] graph, int mouse, int cat, int dp[][]) {

        if (dp[mouse][cat] != -1)
            return dp[mouse][cat];  // use cached value

        dp[mouse][cat] = 0;  // if there is a cycle, draw
        int mouseDefault = 2;  //  default cat win, try to update this number to 1 or 0
        int[] mouseGoList = graph[mouse], catGoList = graph[cat];

        for (int mouseGo : mouseGoList) {
            if (mouseGo == cat)
                continue;   // I'm a mouse, why go for a cat?

            int catDefault = 1;  //  default mouse win, try to update this number to 2 or 0
            for (int catGo : catGoList) {
                if (catGo == 0)
                    continue;  // cannot go to hole
                int next = helper(graph, mouseGo, catGo, dp);
                if (next == 2) {   // if cat win in this path, no need to continue
                    catDefault = 2;
                    break;
                }
                if (next == 0) {   // at least it's a draw
                    catDefault = 0;
                }
            }

            if (catDefault == 1) {  // if mouse can win in this path, no need to continue
                mouseDefault = 1;
                break;
            }
            if (catDefault == 0) {  // at least it's a draw
                mouseDefault = 0;
            }
        }
        dp[mouse][cat] = mouseDefault;
        return dp[mouse][cat];
    }
}
