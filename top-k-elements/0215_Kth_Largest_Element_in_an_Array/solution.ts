/*
215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

import { PriorityQueue } from "./PriorityQueue";
import { MinHeap } from "./MinHeap";
/*
Time complexity is O(NlogK), 
where N is the number of elements in the array and K is the size of the MinHeap.

The space complexity of this approach is  O(K) due to the MinHeap storing up to 
K elements at any time.
*/
function findKthLargest(nums: number[], k: number): number {
  if (k <= 0 || k > nums.length) {
    return -1;
  }

  const minHeap = new MinHeap(k);

  for (let i = 0; i < nums.length; i++) {
    minHeap.insert(nums[i]);
  }

  return minHeap.peek()!;
}

function findKthLargest_PQ(nums: number[], k: number): number {
  if (k <= 0 || k > nums.length) {
    return -1;
  }
  const minHeap = new PriorityQueue((a: number, b: number) => a < b, k);

  for (let i = 0; i < nums.length; i++) {
    // To minHeap, if this.heap[0] < value, we need to re-evaluate the min value in the heap
    minHeap.add(nums[i]);
  }

  return minHeap.peek()!;
}

/*

Approach: Quick Select
Time complexity: O(n) in the average case, O(n^2) in the worst case
*/

function findKthLargest_quickSelect(nums: number[], k: number): number {
  // Helper function to swap elements at indices i and j within nums array
  const swapElements = (i: number, j: number) => {
    [nums[i], nums[j]] = [nums[j], nums[i]];
  };

  // Helper function to implement Quick Select algorithm
  const quickSelect = (left: number, right: number) => {
    // Return early if the partition size is smaller than the kth element we are looking for
    if (left >= right || left + 1 > k) {
      return;
    }

    // Randomly select a pivot and move it to the start
    swapElements(left, left + Math.floor(Math.random() * (right - left)));
    const pivot = nums[left];
    let pivotIndex = left;

    // Partition the array around the pivot
    for (let i = left + 1; i < right; i++) {
      // If the current element is greater than the pivot, swap it with the element
      // at the pivotIndex and increment pivotIndex
      if (nums[i] > pivot) {
        pivotIndex++;
        swapElements(i, pivotIndex);
      }
    }

    // Put the pivot element at its correct position
    swapElements(left, pivotIndex);

    // Recursively apply the same logic to the left and right partitions
    quickSelect(left, pivotIndex);
    quickSelect(pivotIndex + 1, right);
  };

  // Start the quick select process on the entire array
  quickSelect(0, nums.length);

  // Return the kth largest element
  return nums[k - 1];
}
