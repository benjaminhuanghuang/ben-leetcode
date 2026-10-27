/*
2133. Check if Every Row and Column Contains All Numbers

Easy

https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
*/
/*
  Time O(N * (N + 2N))  = O(N^2)
*/
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var checkValid = function (matrix) {
  const n = matrix.length;

  for (let i = 0; i < n; ++i) {
    const row = new Array(n + 1).fill(0);
    const col = new Array(n + 1).fill(0);
    for (let j = 0; j < n; ++j) {
      row[matrix[i][j]] = 1;
      col[matrix[j][i]] = 1;
    }
    //计算有多少 1
    if (row.reduce((s, i) => s + i) < n || col.reduce((s, i) => s + i) < n) {
      return false;
    }
  }

  return true;
};
