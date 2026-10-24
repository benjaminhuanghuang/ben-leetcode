/*
354. Russian Doll Envelopes

https://leetcode.com/problems/russian-doll-envelopes/
*/

/*
Approach: Binary Search + DP
https://www.cnblogs.com/grandyang/p/5568818.html
  
  先建立一个空的 dp 数组，然后开始遍历原数组，对于每一个遍历到的数字，用二分查找法在 dp 数组找第一个不小于它的数字，
  如果这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字，
  如果存在，则将这个数字更新为当前遍历到的数字，最后返回 dp 数组的长度即可
*/

function maxEnvelopes(envelopes: number[][]): number {
  let dp: number[] = [];

  // Sort envelopes by width ascending and by height descending when widths are the same
  envelopes.sort((a, b) => {
    if (a[0] === b[0]) {
      return b[1] - a[1]; // Sort by height descending if widths are the same
    }
    return a[0] - b[0]; // Otherwise, sort by width ascending
  });

  for (let i = 0; i < envelopes.length; ++i) {
    let left = 0,
      right = dp.length,
      t = envelopes[i][1];
    while (left < right) {
      let mid = left + Math.floor((right - left) / 2);
      if (dp[mid] < t) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    if (right >= dp.length) {
      dp.push(t);
    } else {
      dp[right] = t;
    }
  }
  return dp.length;
}
