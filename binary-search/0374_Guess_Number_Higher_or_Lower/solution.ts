/*
374. Guess Number Higher or Lower

https://leetcode.com/problems/guess-number-higher-or-lower/
*/
var guess = function (num: number): number {
  return 0;
};

function guessNumber(n: number): number {
  let l = 1;
  let r = n;

  while (l < r) {
    const mid = l + ((r - l) >> 1);
    if (guess(mid) === 0) {
      return mid;
    } else if (guess(mid) === -1) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  return l;
}
