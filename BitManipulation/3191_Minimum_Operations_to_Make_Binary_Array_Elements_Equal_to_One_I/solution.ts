/*
3191. Minimum Operations to Make Binary Array Elements Equal to One I

https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
*/

/*
    每次反转3个连续的元素
    We notice that the first position in the array that is 
    must undergo a flip operation, otherwise, it cannot be turned into 
    数组中的第一个为0的位置，一定需要进行一次反转操作，否则无法将其变为1。
    因此，我们可以顺序遍历数组，每次遇到0，就将其后两个元素进行反转操作
*/
function minOperations(nums: number[]): number {
  const n = nums.length;
  let ans = 0;
  for (let i = 0; i < n; ++i) {
    if (nums[i] === 0) {
      if (i + 2 >= n) {
        return -1;
      }
      nums[i + 1] ^= 1;
      nums[i + 2] ^= 1;
      ++ans;
    }
  }
  return ans;
}
