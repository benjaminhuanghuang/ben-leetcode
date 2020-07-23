/*
498. Diagonal Traverse

Level: Medium

https://leetcode.com/problems/diagonal-traverse
*/

/*
  Solution: 
  https://www.youtube.com/watch?v=2w3YtiPOEPc

  i +j is even, goes up
  i +j is odd, goes down
*/

/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findDiagonalOrder = function (matrix) {
  if (matrix.length == 0) return [];
  var row = 0,
    col = 0,
    rows = matrix.length,
    cols = matrix[0].length;
  let res = [];

  for (var k = 0; k < cols * rows; k++) {
    res.push(matrix[row][col]);
    if ((row + col) % 2 == 0) {
      // goes up
      if (col == cols - 1) {
        row++;
      } else if (row == 0) {
        col++;
      } else {
        row--;
        col++;
      }
    } else {
      //goes down
      if (row == rows - 1) {
        col++;
      } else if (col == 0) {
        row++;
      } else {
        row++;
        col--;
      }
    }
  }
  return res;
};

export { findDiagonalOrder };
