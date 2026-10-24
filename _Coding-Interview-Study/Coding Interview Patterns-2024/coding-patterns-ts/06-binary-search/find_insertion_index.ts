function findInsertionIndex(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);

    // If nums[mid] is greater than or equal to target,
    // the lower bound could be mid or to the left of mid.
    if (nums[mid] >= target) {
      right = mid;
    } else {
      // Otherwise, the lower bound must be to the right of mid.
      left = mid + 1;
    }
  }

  return left;
}

/*
Time complexity: The time complexity of find_the_insertion_index is O(log(n)) because it
performs a binary search over a search space of size n + 1.

Space complexity: The space complexity is O(1).

*/
