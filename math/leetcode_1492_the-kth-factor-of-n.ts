/* 
1492. The kth Factor of n
https://leetcode.com/problems/the-kth-factor-of-n/
 */

function kthFactor(n: number, k: number): number {
  let count = 0;
  for (let i = 1; i <= n; i++) {
    if (n % i === 0) {
      count++;
      if (count === k) {
        return i;
      }
    }
  }
  return -1;
}
