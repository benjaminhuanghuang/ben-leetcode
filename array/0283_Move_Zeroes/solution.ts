/*
283. Move Zeroes

https://leetcode.com/problems/move-zeroes/
*/

function moveZeroes(nums: number[]): void {
  if (nums.length === 0) {
    return;
  }

  let positionOfZeroes = 0;
  // Push all non-zero elements to the beginning of the array
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      nums[positionOfZeroes] = nums[i];
      positionOfZeroes++;
    }
  }

  // Set the remaining elements to zero
  while (positionOfZeroes < nums.length) {
    nums[positionOfZeroes++] = 0;
  }
}
