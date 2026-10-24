/*
    Time complexity: O(n) because we iterate through the array once.
    Space complexity: O(1) because we use only a constant amount of extra space.
*/

function lonely_integer(nums: number[]): number {
  let res = 0;

  // XOR each element of the array so that duplicate values will
  // cancel each other out (x ^ x == 0).
  for (const num of nums) {
    res ^= num;
  }

  // 'res' will store the lonely integer because it would not have
  // been canceled out by any duplicate.
  return res;
}
