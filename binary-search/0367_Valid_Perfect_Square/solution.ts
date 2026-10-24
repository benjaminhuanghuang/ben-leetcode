/*
367. Valid Perfect Square

https://leetcode.com/problems/valid-perfect-square/
*/

function isPerfectSquare(num: number): boolean {
  if (num < 1) return false;
  if (num === 1) return true;

  let left = 0;
  let right = Math.floor(num / 2);

  /*
    一定有解，使用左闭右闭区间
   */
  while (left <= right) {
    let mid = left + ((right - left) >> 1);
    let square = mid * mid; // mid * mid can be a large number

    if (square === num) {
      return true;
    } else if (square > num) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return false;
}
