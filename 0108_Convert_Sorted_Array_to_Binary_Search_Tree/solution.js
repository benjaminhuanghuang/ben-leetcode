/*
108. Convert Sorted Array to Binary Search Tree

Level: Easy

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
*/

/*
  Solution: 
*/

import { TreeNode } from "../common/commonES6.js"
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
  return buildBST(nums, 0, nums.length - 1)
};


function buildBST(nums, left, right) {
  if (left > right) {
    return null
  }

  const mid = Math.floor((left + right) / 2)
  const root = new TreeNode(nums[mid])
  root.left = buildBST(nums, left, mid - 1)
  root.right = buildBST(nums, mid + 1, right)
  return root
}


export { sortedArrayToBST };