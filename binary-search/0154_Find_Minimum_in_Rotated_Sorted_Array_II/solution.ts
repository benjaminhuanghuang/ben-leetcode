/*
154. Find Minimum in Rotated Sorted Array II

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Rotating the array means moving the last element to the front.

-33. Search in Rotated Sorted Array
-153. Find Minimum in Rotated Sorted Array
区别： 有重复的数字
*/

/*
https://www.youtube.com/watch?v=aCb1zKMimDQ (Hua Hua)


*/
function findMin(nums: number[]): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);

    // If the middle element is greater than the rightmost element, the minimum is to the right
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    }
    // If the middle element is less than the rightmost element, the minimum is to the left or at midIndex
    else if (nums[mid] < nums[right]) {
      right = mid;
    }
    // If the middle element is equal to the rightmost element, we can't decide where the minimum is, move the right pointer left
    else {
      right--;
    }
  }

  // At the end of the loop, leftIndex is the smallest value
  return nums[left];
}
