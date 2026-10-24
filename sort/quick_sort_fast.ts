// Helper function to perform the quickSort algorithm.
function quickSort(nums: number[], left: number, right: number) {
  if (left >= right) {
    return;
  }

  let i = left - 1;
  let j = right + 1;

  // Choose the pivot element from the middle of the segment.
  const pivot = nums[(left + right) >> 1];

  // Partition process: elements < pivot go to the left, elements > pivot go to the right.
  while (i < j) {
    // Find left element greater than or equal to the pivot.
    while (nums[++i] < pivot);
    // Find right element less than or equal to the pivot.
    while (nums[--j] > pivot);

    // If pointers have not crossed, swap the elements.
    if (i < j) {
      [nums[i], nums[j]] = [nums[j], nums[i]];
    }
  }

  // Recursively apply the same logic to the left partition.
  quickSort(nums, left, j);
  // Recursively apply the same logic to the right partition.
  quickSort(nums, j + 1, right);
}
