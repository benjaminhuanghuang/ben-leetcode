/*
80. Remove Duplicates from Sorted Array II

*/

/*
https://www.youtube.com/watch?v=ycAq8iqh0TI
*/
export function removeDuplicates(nums: number[]): number {
  let uniqueCursor = 0;

  for (let num of nums) {
    if (uniqueCursor < 2 || num > nums[uniqueCursor - 2])
      nums[uniqueCursor++] = num;
  }

  return uniqueCursor;
}
