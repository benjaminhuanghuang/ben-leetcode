/*
75. Sort Colors

Level: Medium

https://leetcode.com/problems/sort-colors
*/

/*
  Solution: 
*/

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function (nums) {
  if (nums == null || nums.length == 0) {
    return;
  }
  let lastRed = 0,
    firstBlue = nums.length - 1;
  let i = 0;
  while (i <= firstBlue) {
    if (nums[i] == 0 && i != lastRed) {
      swap(nums, lastRed++, i);
    } else if (nums[i] == 2 && i != firstBlue) {
      swap(nums, i, firstBlue--);
    } else ++i;
  }
};
const swap = (nums, i, j) => {
  const temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
export { sortColors };
