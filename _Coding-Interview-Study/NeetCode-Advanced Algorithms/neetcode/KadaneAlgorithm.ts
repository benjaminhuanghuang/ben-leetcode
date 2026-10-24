/*
Find a non-empty subarray of nums that has the largest sum
*/

/*
Time Complexity: O(n^2)
 */
function bruteForce(nums: number[]): number {
  let maxSum = nums[0];

  for (let i = 0; i < nums.length; i++) {
    let curSum = 0;
    for (let j = i; j < nums.length; j++) {
      curSum += nums[j];
      maxSum = Math.max(maxSum, curSum);
    }
  }

  return maxSum;
}

/*
对于每个位置 i，只需做一个决策： 要不要把前面的子数组带上？
curSum = Math.max(nums[i], curSum + nums[i])

如果：前面的累计和是负担，抛弃，从当前重新开始, 选 nums[i]
如果：前面的累计和是有用的，继续累加 选 curSum + nums[i]

Time Complexity: O(n)
Space Complexity: O(1)
*/
function kadane(nums: number[]): number {
  let maxSum = nums[0];
  let curSum = nums[0];

  for (let i = 1; i < nums.length; i++) {
    curSum = Math.max(nums[i], curSum + nums[i]);
    maxSum = Math.max(maxSum, curSum);
  }

  return maxSum;
}
