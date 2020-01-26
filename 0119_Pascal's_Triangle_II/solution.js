/*
119. Pascal's Triangle II

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

*/

var getItem = function (row, j) {
  if (j < 0 || j >= row.length)
    return 0;
  return row[j];
}

var getRow_MLE = function (rowIndex) {
  var row = [1];
  for (var i = 0; i < rowIndex; i++) {
    var newRow = [];
    for (var j = 0; i <= i + 1; j++) {
      var digit = getItem[row, j - 1] + getItem(row, j);
      newRow.push(digit);
    }
    row = newRow;
  }
  return row;
};
/*
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
    ]
*/
var getRow = function (rowIndex) {
  var res = [];
  if (rowIndex < 0) return res;

  for (var row = 0; row <= rowIndex; row++) {
    // Add 1 to the row
    res.unshift(1);
    // Calculate the values
    for (var col = 1; col < res.length - 1; col++) {
      res[col] = res[col] + res[col + 1];
    }
  }
  return res;
}; å