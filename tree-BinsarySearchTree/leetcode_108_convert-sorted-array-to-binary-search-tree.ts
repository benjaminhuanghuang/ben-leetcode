/*
108. Convert Sorted Array to Binary Search Tree

*/

import { TreeNode } from "../Common/TreeNode";

/*
Time Complexity: O(n)
*/
function sortedArrayToBST(nums: number[]): TreeNode | null {
  return sortedArrayToBSTCore(nums, 0, nums.length - 1);
}

function sortedArrayToBSTCore(
  nums: number[],
  left: number,
  right: number
): TreeNode | null {
  if (right >= left) {
    const mid = left + Math.floor((right - left) / 2);
    const leftSub = sortedArrayToBSTCore(nums, left, mid - 1);
    const rightSub = sortedArrayToBSTCore(nums, mid + 1, right);

    return new TreeNode(nums[mid], leftSub, rightSub);
  }

  return null;
}
