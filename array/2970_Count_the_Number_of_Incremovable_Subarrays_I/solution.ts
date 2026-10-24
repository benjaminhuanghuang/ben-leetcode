/*
2970. Count the Number of Incremovable Subarrays I

https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/
*/

/*
https://algo.monster/liteproblems/2970

1. if the array itself is already strictly increasing, then any subarray, including an empty one, is potentially incremovable
2. when the array is not strictly increasing, only particular subarrays can be removed to achieve this state

如果我们有一个严格递增的前缀，则可以删除任何从该前缀之后立即开始并延伸到数组末尾的子数组，以维持严格递增的序列。
if nums[0] < nums[1]... < nums[i],  we can remove array
nums[i+1]...nums[n-1]
nums[i]...nums[n-1]
nums[i-1]...nums[n-1]
...
nums[0]...nums[n-1]
共有 i+2 个子数组可以删除

如果我们有一个严格递增的后缀，可以类似地删除任何在后缀之前立即结束并在后缀之前的任何位置开始的子数组（甚至从数组的开始）。
j is 递增后缀的第一个元素, 在1到n-1之间枚举j， 每次移动i使得nums[i] < nums[j]， 移除递增子数组的数组增加 i+2
对于最长前缀和后缀之间存在元素阻止整个数组严格递增的情况，我们需要检查可以删除多少个子数组以保留严格递增的前缀和后缀。

*/
function incremovableSubarrayCount(nums: number[]): number {
  const n = nums.length;
  let i = 0;
  // Find the length of the initial strictly increasing sequence.
  while (i + 1 < n && nums[i] < nums[i + 1]) {
    i++;
  }
  // If the entire array is increasing,
  // return the sum of all lengths of subarrays possible.
  if (i === n - 1) {
    return (n * (n + 1)) / 2;
  }
  // Initialize answer with the case where we remove the first element.
  let ans = i + 2;
  for (let j = n - 1; j; --j) {
    while (i >= 0 && nums[i] >= nums[j]) {
      --i;
    }
    ans += i + 2;
    if (nums[j - 1] >= nums[j]) {
      break;
    }
  }
  return ans;
}
