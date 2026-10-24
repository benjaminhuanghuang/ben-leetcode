/*
209. Minimum Size Subarray Sum

https://leetcode.com/problems/minimum-size-subarray-sum/

minimal length of a  subarray whose sum is greater than or equal to target. 
*/
/*
Sliding window: move right pointer, when check the sum >= target, move left pointer to find the minimal length.

Time complexity: O(n) 
 The inner while loop only increases j and decreases the sum s until the sum is less than the target, 
 but j can never be increased more than n times throughout the execution of the algorithm. 
 Therefore, each element is processed at most twice, once when it is added to s and once when it is subtracted, leading to a linear time complexity.
*/
function minSubArrayLen(target: number, nums: number[]): number {
  let left = 0;
  let sum = 0;
  // A large value used to initially represent an impossibly large subarray length.
  // This value will later be used to determine if a valid subarray was found.
  let result = Number.MAX_SAFE_INTEGER;

  for (let right = 0; right < nums.length; right++) {
    sum += nums[right];
    while (sum >= target) {
      result = Math.min(result, right - left + 1);
      sum -= nums[left];
      left++;
    }
  }

  return result === Number.MAX_SAFE_INTEGER ? 0 : result;
}
