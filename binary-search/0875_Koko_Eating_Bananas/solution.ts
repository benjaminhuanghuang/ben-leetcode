/*
875. Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas/
*/

function minEatingSpeed(piles: number[], h: number): number {
  let left = 1;
  let right = Math.max(...piles) + 1;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    let hours = 0;
    for (const pile of piles) {
      hours += Math.ceil(pile / mid);
    }
    if (hours <= h) {
      // g(m) mines can finish, find the smallest value to satisfy g()
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
