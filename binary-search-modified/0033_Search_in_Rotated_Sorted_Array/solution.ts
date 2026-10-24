/*
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

/* 
   4 5 6 7 1 0 2
   
    left part/
              /right part
*/
function search(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length - 1;

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);

    if (nums[mid] === target) {
      return mid;
    }

    if (nums[left] <= nums[mid]) {
      // mid located in left part, which is increasing
      if (nums[left] <= target && target < nums[mid]) {
        //  target located between left and mid
        right = mid - 1;
      } else {
        //  target is bigger than mid
        left = mid + 1;
      }
    } else {
      // nums[l] > nums[mid] , mid located in right part, which is increasing
      if (nums[mid] < target && target <= nums[right]) {
        //target located between mid and right
        left = mid + 1;
      } else {
        // target is less than mid
        right = mid - 1;
      }
    }
  }

  return -1;
}

/*
 Hua Hua
 https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-33-search-in-rotated-sorted-array/
*/
function search_2(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);
    // If nums[mid] and target are "on the same side" of the pivot, we just take nums[mid].
    // If both nums[mid] and target are either both less than nums[0] or both greater than or equal to nums[0], they are on the same side of the pivot.

    // If nums[mid] and target are on the different side of the pivot:
    // If nums[mid] and target are on different sides of the pivot, x is set to a value that will ensure the correct movement of the binary search pointers (left and right).
    // If the target is less than nums[0], x is set to Number.NEGATIVE_INFINITY to ensure mid is considered too large and the search continues in the lower half.
    // If the target is greater than or equal to nums[0], x is set to Number.POSITIVE_INFINITY to ensure mid is considered too small and the search continues in the upper half.

    const x =
      nums[mid] < nums[0] == target < nums[0]
        ? nums[mid]
        : target < nums[0]
          ? Number.MIN_SAFE_INTEGER
          : Number.MAX_SAFE_INTEGER;
    if (x < target) {
      left = mid + 1; // Move right if x is less than target
    } else if (x > target) {
      right = mid; // Move left if x is greater than target
    } else {
      return mid;
    }
  }

  return -1;
}
