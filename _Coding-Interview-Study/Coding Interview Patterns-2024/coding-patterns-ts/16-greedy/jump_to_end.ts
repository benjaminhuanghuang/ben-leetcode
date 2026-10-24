/*
Each number in the array represents the maximum jump distance from the current index. 
Determine if it's possible to reach the end of the array.
*/
function jump_to_end(nums: number[]): boolean {
  // Set the initial destination to the last index
  let destination = nums.length - 1;

  // Traverse backwards to see if we can reach the destination
  for (let i = nums.length - 1; i >= 0; i--) {
    // If from index i we can reach or go beyond the destination,
    // update the destination to i
    if (i + nums[i] >= destination) {
      destination = i;
    }
  }

  // If we can move the destination back to index 0,
  // then we can jump to the end from the start
  return destination === 0;
}

/*
Time complexity: O(n), where n denotes the length of the array. This is because we iterate through each element of nums in reverse order.

Space complexity: O(1), due to the use of a constant amount of extra space.
*/
