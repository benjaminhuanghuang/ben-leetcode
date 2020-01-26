/*
542. 01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
 */
using System;
using System.Collections.Generic;

//http://www.debugrun.com/a/7gjTMuh.html
public class Solution542
{
    public int[,] UpdateMatrix(int[,] matrix)
    {
        int m = matrix.GetLength(0);
        int n = matrix.GetLength(1);

        Queue<int[]> queue = new Queue<int[]>();
        // 对待求矩阵进行一次变换，遇0元素不变，遇1元素设为最大值
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i, j] == 0)
                {
                    queue.Enqueue(new int[] { i, j });
                }
                else
                {
                    matrix[i, j] = int.MaxValue;
                }
            }
        }

        List<int[]> dirs = new List<int[]> { new int[] { -1, 0 },
                                             new int[] { 1, 0 },
                                             new int[] { 0, -1 },
                                             new int[] { 0, 1 } };

        while (queue.Count > 0)
        {
            int[] cell = queue.Dequeue();  // the cell has value 0
            foreach (int[] dir in dirs)
            {
                int row = cell[0] + dir[0];
                int col = cell[1] + dir[1];
                if (row < 0 || row >= m || col < 0 || col >= n ||
                    matrix[row, col] <= matrix[cell[0],cell[1]] + 1)
                    continue;
                //由于0元素的影响是传递的，所以受它影响的inf节点必须得放入队列中
                queue.Enqueue(new int[] { row, col });
                //碰到【inf】，则+1，但前提是当前【inf】节点的值大于原先的值+1。
                matrix[row, col] = matrix[cell[0], cell[1]] + 1;
            }
        }

        return matrix;
    }
}