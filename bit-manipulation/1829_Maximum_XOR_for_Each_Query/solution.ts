/*
1829. Maximum XOR for Each Query

https://leetcode.com/problems/maximum-xor-for-each-query/
*/

function getMaximumXor(nums: number[], maximumBit: number): number[] {
  let cumulativeXor = 0;
  for (const num of nums) {
    cumulativeXor ^= num;
  }

  // Calculate the mask to get the maximum XOR by setting maximumBit bits to 1
  const mask = (1 << maximumBit) - 1;

  const length = nums.length;

  const answer = new Array(length);

  for (let i = 0; i < length; ++i) {
    // Find the current number by indexing from the end of the nums array.
    const currentNum = nums[length - i - 1];
    // Calculate the maximum XOR for the current number as per the problem statement.
    let maxXor = cumulativeXor ^ mask;
    answer[i] = maxXor;
    cumulativeXor ^= currentNum;
  }

  return answer;
}
