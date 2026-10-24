/*
278. First Bad Version

https://leetcode.com/problems/first-bad-version/
*/

function isBadVersion(version: number): boolean {
  return false;
}

var solution = function (isBadVersion: any) {
  return function (n: number): number {
    let left = 0;
    let right = n;
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (isBadVersion(mid)) {
        // Find the smallest value to satisfy g()
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  };
};
