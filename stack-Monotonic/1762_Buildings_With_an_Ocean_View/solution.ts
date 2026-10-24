/*
1762. Buildings With an Ocean View

https://leetcode.com/problems/buildings-with-an-ocean-view/
*/

/*
https://algo.monster/liteproblems/1762
*/

function findBuildings(heights: number[]): number[] {
  // Create an array to store the indices of the buildings with an ocean view.
  const buildingsWithViews: number[] = [];
  // Initialize a variable to keep track of the maximum height found so far as we iterate from right to left.
  let maxHeight = 0;

  // Start iterating from the last building towards the first.
  for (let i = heights.length - 1; i >= 0; --i) {
    // Check if the current building height is greater than the maximum height found.
    if (heights[i] > maxHeight) {
      // If so, add the index of this building to our result array.
      buildingsWithViews.push(i);
      // Update maxHeight to the height of the current building.
      maxHeight = heights[i];
    }
  }

  // Since we traversed the buildings from right to left, the resulting array is in reverse order.
  // Reverse the array to return the indices in the correct order, from left to right.
  return buildingsWithViews.reverse();
}
