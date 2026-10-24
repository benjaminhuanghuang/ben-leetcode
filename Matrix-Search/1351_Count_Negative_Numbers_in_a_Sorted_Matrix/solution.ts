/*
1351. Count Negative Numbers in a Sorted Matrix

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

/*
[[4,3,2,-1],
 [3,2,1,-1],
 [1,1,-1,-2],
 [-1,-1,-2,-3]
]
 左上角的较大到右下角的较小
 查找负数从矩阵的左下角开始（grid[m - 1][0], 
 if grid[row][col]<0，那么它右边的所有数字都保证是负数，因为该行是按非递增顺序排序的, and check row--
 else check the next column。

外循环最多运行m
内部条件可导致向右移动最多至n列。
但是，一旦离开某行或某列，就永远不会再访问该行或该列（因为如果找到负数，则向上移动；如果找到非负数，则向右移动），
这意味着每个单元格最多被访问一次。
Time complexity is O(m + n)。
*/
function countNegatives(grid: number[][]): number {
  const rowCount = grid.length;
  const columnCount = grid[0].length;

  let negativeCount = 0;

  // Start from the bottom-left corner of the grid
  let row = rowCount - 1;
  let column = 0;

  // Loop until we reach the top of the grid or the end of a row
  while (row >= 0 && column < columnCount) {
    // If the current number is negative,
    // add all remaining negatives in the row to the counter
    // (as the row is sorted in non-increasing order)
    if (grid[row][column] < 0) {
      // All numbers to the right of the current position are negative
      negativeCount += columnCount - column;
      // Move up to the previous row since we've counted all negatives in the current row
      row--;
    } else {
      // If the current number is non-negative, move right to the next column
      column++;
    }
  }

  // Return total count of negative numbers
  return negativeCount;
}
