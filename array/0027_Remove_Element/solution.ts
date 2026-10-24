/*
  27. Remove Element
*/

/*
    Two-point & same direction, 
    One pointer for iteration, while the other pointer marks the completed section.
*/
function removeElement(nums: number[], val: number): number {
  let pivot = 0;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== val) {
      nums[pivot] = nums[i];
      pivot++;
    }
  }

  return pivot++; // return the count of the numbers
}
