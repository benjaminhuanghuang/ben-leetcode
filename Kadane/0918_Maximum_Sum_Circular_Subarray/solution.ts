/*
918. Maximum Sum Circular Subarray

https://leetcode.com/problems/maximum-sum-circular-subarray/
*/

/*
case 1     [...][ the max subarray is in the middle][...]
case 2     [the max subarray left][...][the max subarray right]
    for case2 we can find the min subarray sum, then answer = total sum - min subarray sum
*/
function maxSubarraySumCircular(nums: number[]): number {
  const case1 = findMax(nums);
  const total = nums.reduce((acc, cur) => acc + cur);

  const oppositeNums = nums.map((num) => -num);
  const case2 = total + findMax(oppositeNums);
  // Handling the edge case where all numbers are negative
  // The case1 is one of the negative number, case2 is 0
  if (case2 === 0) {
    return case1;
  }
  return Math.max(case1, case2);
}

function findMax(nums: number[]): number {
  let maxEndingHere = nums[0];
  let maxSoFar = nums[0];

  for (let i = 1; i < nums.length; i++) {
    maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
    maxSoFar = Math.max(maxSoFar, maxEndingHere);
  }

  return maxSoFar;
}
