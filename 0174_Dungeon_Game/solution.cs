/*
174. Dungeon Game [Hard]

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
*/
using System;
public class Solution174 {
    public int CalculateMinimumHP(int[,] dungeon) {
        var lenRow = dungeon.GetLength(0);
        var lenColumn = dungeon.GetLength(1);

        var minimumHP = new int[lenRow, lenColumn];

        minimumHP[lenRow - 1, lenColumn - 1] = dungeon[lenRow - 1, lenColumn - 1] > 0 ? 1 : 1 - dungeon[lenRow - 1, lenColumn - 1];

        for (int i = lenRow - 2; i >= 0; i--)
        {
            minimumHP[i, lenColumn - 1] = Math.Max(1 ,minimumHP[i + 1, lenColumn - 1] - dungeon[i, lenColumn - 1]);
        }

        for (int i = lenColumn - 2; i >= 0; i--)
        {
            minimumHP[lenRow - 1, i] = Math.Max(1 , minimumHP[lenRow - 1, i + 1] - dungeon[lenRow - 1, i]);
        }

        for (int i = lenRow - 2; i >= 0; i--)
        {
            for (int j = lenColumn - 2; j >= 0; j--)
            {
                var right = Math.Max(1, minimumHP[i, j + 1] - dungeon[i, j]);
                var up = Math.Max(1, minimumHP[i + 1, j] - dungeon[i, j]);
                minimumHP[i, j] = Math.Min(right, up);
            }
        }

        return minimumHP[0, 0];
    }
}