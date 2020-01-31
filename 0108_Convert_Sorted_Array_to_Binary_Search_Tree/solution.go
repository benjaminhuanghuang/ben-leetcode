/*
108. Convert Sorted Array to Binary Search Tree

Level: Easy

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
*/
package leetcode0108

import (
	. "../common"
)

/*

 */

func sortedArrayToBST(nums []int) *TreeNode {
	return buildBST(nums, 0, len(nums))
}

/*
left right 使用 左闭右开
以case[0,1,2,3] 为例 left = 0 , right = 4, (0+4)/2 = 2 正好把数组分为 [0,1] and [2,3]

使用左闭右闭也可以，但是生成的tree会不同
*/
func buildBST(nums []int, left int, right int) *TreeNode {
	if left >= right {
		return nil
	}

	mid := left + (right-left)/2
	root := &TreeNode{
		Val:   nums[mid],
		Left:  buildBST(nums, left, mid),
		Right: buildBST(nums, mid+1, right),
	}
	return root
}
