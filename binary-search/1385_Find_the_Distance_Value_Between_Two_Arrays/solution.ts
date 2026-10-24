/*
1385. Find the Distance Value Between Two Arrays

https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
*/

function findTheDistanceValue(
  arr1: number[],
  arr2: number[],
  d: number
): number {
  // Helper function that checks if any element in arr2 is within d distance of element 'value'
  const isElementDistanceValid = (value: number): boolean => {
    let left = 0;
    let right = arr2.length;
    while (left < right) {
      // Find the middle index
      const middle = Math.floor((left + right) / 2);
      // Check if the middle element is within the allowed distance
      if (arr2[middle] >= value - d) {
        right = middle; // Element is too close, adjust the search range to the left
      } else {
        left = middle + 1; // Element is not close enough, adjust the search range to the right
      }
    }
    // If left is equal to length of arr2 or the element at 'left' index is outside the distance 'd' from 'value', return true
    return left === arr2.length || arr2[left] > value + d;
  };

  // Sort the second array to enable binary search
  arr2.sort((a, b) => a - b);
  // Initialize the count of elements that satisfy the condition
  let validElementCount = 0;
  // Iterate through the elements of arr1
  for (const value of arr1) {
    // Check if the current element satisfies the distance condition for every element in arr2
    if (isElementDistanceValid(value)) {
      // If condition is met, increment the count
      validElementCount++;
    }
  }
  // Return the final count of valid elements
  return validElementCount;
}
