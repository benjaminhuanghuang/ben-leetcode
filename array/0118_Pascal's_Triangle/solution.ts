/*
118. Pascal's Triangle

https://leetcode.com/problems/pascals-triangle/
*/

/*
[
  [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]
]
*/
function generate(numRows: number): number[][] {
  const res: number[][] = [];

  for (let row = 0; row < numRows; row++) {
    const nums: number[] = [];
    for (let col = 0; col <= row; col++) {
      if (col === 0 || col === row) {
        nums.push(1);
      } else {
        nums.push(res[row - 1][col - 1] + res[row - 1][col]);
      }
    }
    res.push(nums);
  }

  return res;
}
