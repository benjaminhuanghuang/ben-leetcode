/*
26. Remove Duplicates from Sorted Array

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

/*
Given a sorted array nums, remove the duplicates in-place such that each element appears 
only once and returns the new length.
*/
export function removeDuplicates(nums: number[]): number {
  let uniqueCursor = 1;

  for (let i = 1; i < nums.length; i++) {
    // Find unique values
    if (nums[i] !== nums[i - 1]) {
      // Move unique values to follow the last unique value found
      nums[uniqueCursor] = nums[i];

      // Move the unique value cursor onward
      uniqueCursor++;
    }
  }

  return uniqueCursor;
}
