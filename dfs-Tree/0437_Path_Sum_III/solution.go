/*
437. Path Sum III

Level: Easy

https://leetcode.com/problems/path-sum-iii
*/

package leetcode0437

/*

 */

import (
	. "..common"
)

func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	return pathCounter(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func pathCounter(root *TreeNode, sum int) int{
	res := 0
	if root == nil{
		return 0
	}
	if sum == root.val{
		res ++
	}
	res += pathCounter(root.Left, sum - root.Val)
	res += pathCounter(root.Right, sum - root.Val)
	return res
}
