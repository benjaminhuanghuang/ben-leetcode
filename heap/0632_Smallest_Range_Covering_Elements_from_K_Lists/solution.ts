/*
632. Smallest Range Covering Elements from K Lists

https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
*/

import { PriorityQueue } from "./PriorityQueue";

/*
Lai Offer
https://www.youtube.com/watch?v=csJXQZFYklE

Set pointers for every list and move them only when it is pointing the current smallest
number among all lists(with PriorityQueue's help).

Keep the difference between the numbers pointers pointing as small as possible
*/
function smallestRange1(nums: number[][]): [number, number] {
  let minx = 0,
    miny = Number.MAX_VALUE,
    max = Number.MIN_VALUE;
  const next = new Array(nums.length).fill(0);
  let flag = true;

  // Compare by the current pointing number's value
  const minQueue = new PriorityQueue<number>(
    (i, j) => nums[i][next[i]] < nums[j][next[j]]
  );

  for (let i = 0; i < nums.length; i++) {
    minQueue.add(i);
    max = Math.max(max, nums[i][0]);
  }

  while (flag) {
    const min_i = minQueue.poll()!;

    if (miny - minx > max - nums[min_i][next[min_i]]) {
      minx = nums[min_i][next[min_i]];
      miny = max;
    }

    next[min_i]++;
    if (next[min_i] === nums[min_i].length) {
      flag = false;
      break;
    }

    minQueue.add(min_i);
    max = Math.max(max, nums[min_i][next[min_i]]);
  }

  return [minx, miny];
}
/*
    https://algo.monster/liteproblems/632
    Approach: 
*/
function smallestRange(nums: number[][]): number[] {
  // Calculate the total number of elements across all lists.
  const totalElements = nums.reduce((acc, group) => acc + group.length, 0);

  // Create an array to store tuples of values and their corresponding list index.
  const sortedElements: [number, number][] = new Array(totalElements);

  // Flatten all values along with their list index into the `sortedElements` array.
  let index = 0;
  for (let i = 0; i < nums.length; ++i) {
    for (const value of nums[i]) {
      sortedElements[index++] = [value, i];
    }
  }

  // Sort the elements based on the numeric values.
  sortedElements.sort(([val1], [val2]) => val1 - val2);

  // Initialize the pointers and a Map to track the count of each list's presence in the current window.
  let startWindow = 0;
  const groupCount = new Map<number, number>();

  // Initialize the answer with a large possible range.
  let range: number[] = [-1000000, 1000000];

  // Iterate through the sorted elements to find the minimum range.
  for (let endWindow = 0; endWindow < totalElements; ++endWindow) {
    const [currentValue, currentGroup] = sortedElements[endWindow];

    // Update the count of the current group.
    groupCount.set(currentGroup, (groupCount.get(currentGroup) || 0) + 1);

    // Attempt to shrink the window from the left if all groups are present.
    while (groupCount.size === nums.length) {
      const [windowStartValue, windowStartGroup] = sortedElements[startWindow];

      // Update the range if the current one is better.
      const currentRange = currentValue - windowStartValue;
      const bestRange = range[1] - range[0];
      if (
        currentRange < bestRange ||
        (currentRange === bestRange && windowStartValue < range[0])
      ) {
        range = [windowStartValue, currentValue];
      }

      // Decrease the count of the starting group's element and remove it if the count becomes zero.
      const startGroupCount = groupCount.get(windowStartGroup)! - 1;
      if (startGroupCount === 0) {
        groupCount.delete(windowStartGroup);
      } else {
        groupCount.set(windowStartGroup, startGroupCount);
      }

      // Move the window start forward.
      startWindow++;
    }
  }

  // Return the smallest range found.
  return range;
}
