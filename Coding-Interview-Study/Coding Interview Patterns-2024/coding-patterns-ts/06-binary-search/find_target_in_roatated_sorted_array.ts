function find_target_in_roatated_sorted_array(
  nums: number[],
  target: number
): number {
  let left = 0;
  let right = nums.length - 1;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);

    if (nums[mid] === target) {
      return mid;
    }

    // Case 1: target is in [left..mid]
    if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target < nums[mid]) {
        right = mid - 1; // target lies in left sorted half
      } else {
        left = mid + 1; // search in right half
      }
    }
    // Case 2: target is in [mid..right]
    else {
      if (nums[mid] < target && target <= nums[right]) {
        left = mid + 1; // target lies in right sorted half
      } else {
        right = mid - 1; // search in left half
      }
    }
  }

  // After the loop, check if target is found
  // if the input array nums is empty ([]), then left = 0, right = -1, and the while (left < right) loop will never run.
  return nums.length > 0 && nums[left] === target ? left : -1;
}

/*
Time complexity: The time complexity of find_the_target_in_a_rotated_sorted_array is
O(log( n)) because we' re performing a binary search over an array of length n.

Space complexity: The space complexity is 0(1).
*/
