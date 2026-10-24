/*
  Time Complexity: O(N) where N is the length of the input array.
  Space Complexity: O(1)
*/
export function shiftZerosToTheEnd(nums: number[]): void {
  // The 'left' pointer is used to position non-zero elements.
  let left = 0;
  // Iterate through the array using a 'right' pointer to locate non-zero
  // elements.
  for (let right = 0; right < nums.length; right++) {
    if (nums[right] !== 0) {
      [nums[left], nums[right]] = [nums[right], nums[left]];
      // Increment 'left' since it now points to a position already occupied
      // by a non-zero element.
      left++;
    }
  }
}
