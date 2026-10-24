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