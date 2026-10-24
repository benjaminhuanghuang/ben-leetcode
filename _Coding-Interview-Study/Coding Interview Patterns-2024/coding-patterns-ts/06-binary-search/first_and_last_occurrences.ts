function firstAndLastOccurrences(nums: number[], target: number): number[] {
  const lowerBound = lowerBoundBinarySearch(nums, target);
  const upperBound = upperBoundBinarySearch(nums, target);
  return [lowerBound, upperBound];
}

function lowerBoundBinarySearch(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length - 1;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);

    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid; // move left to find the first occurrence
    }
  }

  return nums.length > 0 && nums[left] === target ? left : -1;
}
function upperBoundBinarySearch(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length - 1;

  while (left < right) {
    // Bias the midpoint to the right
    const mid = Math.floor((left + right) / 2) + 1;

    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      left = mid; // move right to find the last occurrence
    }
  }

  return nums.length > 0 && nums[right] === target ? right : -1;
}

/*
Time complexity: The time complexity of both the lower bound_binary_search and
upper bound_binary_search helper functions is O(log(n)), where n denotes the length of the
input array. This is because each function performs a binary search over the entire array. Therefore,
first_and_last_occurrences_of a_number is also O(log(n)) because it calls each helper
function once.

Space complexity: The space complexity is O(1).
*/
