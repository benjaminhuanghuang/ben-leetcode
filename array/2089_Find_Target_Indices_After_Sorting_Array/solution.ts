/*
2089. Find Target Indices After Sorting Array

https://leetcode.com/problems/find-target-indices-after-sorting-array/
*/

function targetIndices(nums: number[], target: number): number[] {
  // Sort the array in ascending order.
  nums.sort((a, b) => a - b);

  // Initialize an array to store the indices where target is found.
  let resultIndices: number[] = [];

  // Iterate over the sorted array to find all occurrences of target.
  for (let index = 0; index < nums.length; index++) {
    // Check if the current element is equal to the target.
    if (nums[index] === target) {
      // If it is, add the current index to the resultIndices array.
      resultIndices.push(index);
    }
  }

  // Return the array of indices where target is found.
  return resultIndices;
}
