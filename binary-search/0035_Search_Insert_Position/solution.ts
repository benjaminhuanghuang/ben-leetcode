/*
35. Search Insert Position

https://leetcode.com/problems/search-insert-position/
*/

/*
    Use huahua's template
*/
function searchInsert(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    let mid = left + Math.floor((right - left) / 2);
    if (nums[mid] === target) return mid;

    // Find the minimum left that nums[left]>=target
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

export {};
