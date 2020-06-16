/*
1480. Running Sum of 1d Array

Level: Easy

https://leetcode.com/problems/running-sum-of-1d-array
*/

/*
  Solution: 
*/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function (nums) {
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    let n = nums[i];
    nums[i] += sum;
    sum += n;
  }
  return nums;
};

export { runningSum };
