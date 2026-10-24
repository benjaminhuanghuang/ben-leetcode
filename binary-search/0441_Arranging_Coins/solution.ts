/*
441. Arranging Coins

https://leetcode.com/problems/arranging-coins/
*/

function arrangeCoins(n: number): number {
  let l = 1;
  let r = n;

  //[l, r] used to find the only certain answer
  while (l <= r) {
    let m = l + Math.floor((r - l) / 2);
    let total = (m * (m + 1)) / 2;

    if (total === n) {
      return m; // return the biggest number <= target
    } else if (total > n) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return r; // return the biggest number <= target
}
