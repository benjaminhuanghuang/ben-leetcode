/*
53. Maximum Subarray

https://leetcode.com/problems/maximum-subarray/
*/

/*
    当前和为sum,如果sum >0,那么加上当前元素，否则sum=A[i] （即抛弃负数的sum，重新开始。因为负数的sum是累赘)
*/
function maxSubArray(nums: number[]): number {
  let maxSum = nums[0];
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    if (sum > 0) {
      sum += nums[i];
    } else {
      sum = nums[i];
    }
    if (sum > maxSum) maxSum = sum;
  }
  return maxSum;
}

function maxSubArray_Kadane(nums: number[]): number {
  let maxEndingHere = nums[0];
  let maxSoFar = nums[0];

  for (let i = 1; i < nums.length; i++) {
    maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
    maxSoFar = Math.max(maxSoFar, maxEndingHere);
  }

  return maxSoFar;
}
