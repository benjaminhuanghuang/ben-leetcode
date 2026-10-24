/*
3200. Maximum Height of a Triangle

https://leetcode.com/problems/maximum-height-of-a-triangle/
*/

function maxHeightOfTriangle(red: number, blue: number): number {
  let ans = 0;

  for (let color = 0; color < 2; ++color) {
    const balls: [number, number] = [red, blue];
    // i^=1 , switch between 0 and 1
    for (let row = 1, i = color; row <= balls[i]; ++row, i ^= 1) {
      balls[i] -= row; // pull N balls in row N (1 index)
      ans = Math.max(ans, row);
    }
  }
  return ans;
}
