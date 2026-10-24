/*
2317. Maximum XOR After Operations

https://leetcode.com/problems/maximum-xor-after-operations/
*/

/*
https://zxi.mytechroad.com/blog/bit/leetcode-2317-maximum-xor-after-operations/ (Huahua)
*/
function maximumXOR(nums: number[]): number {
  return nums.reduce((acc, num) => acc | num, 0);
}
