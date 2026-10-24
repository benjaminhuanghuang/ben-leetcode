/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx/
*/

/*
    Use Huahua's template
    https://www.youtube.com/watch?v=v57lNF2mb_s&t=212s
 */

function mySqrt(x: number): number {
  let left = 0;
  let right = x + 1;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (mid * mid > x) {
      // Find the smallest value to satisfy g()
      right = mid;
    } else left = mid + 1;
  }
  return left - 1;
}
/*
因为一定有解，使用左闭右闭区间
 */
function mySqrt_2(x: number): number {
  if (x < 2) return x;

  let left = 1;
  let right = x;

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);

    // 为避免 mid * mid 溢出（虽然 JS number 不会溢出，但保持逻辑一致）
    const div = Math.floor(x / mid);

    if (mid === div) {
      return mid;
    } else if (mid < div) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  // 当 loop 结束时，right < left，right 是满足 mid*mid ≤ x 的最大 mid
  return right;
}
