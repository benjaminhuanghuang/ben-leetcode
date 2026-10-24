/*
1200. Minimum Absolute Difference

https://leetcode.com/problems/minimum-absolute-difference/
*/

function minimumAbsDifference(arr: number[]): number[][] {
  let ans: number[][] = [];
  arr.sort((a, b) => a - b);

  let minDiff = Number.MAX_SAFE_INTEGER;
  for (let i = 1; i < arr.length; ++i) {
    const diff = arr[i] - arr[i - 1];
    if (diff < minDiff) {
      minDiff = diff;
      ans = [[arr[i - 1], arr[i]]];
    } else if (diff === minDiff) {
      ans.push([arr[i - 1], arr[i]]);
    }
  }
  return ans;
}
