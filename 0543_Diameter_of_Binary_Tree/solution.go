/*
543. Diameter of Binary Tree

Level: Easy

https://leetcode.com/problems/diameter-of-binary-tree
*/
package leetcode0543

/*

 */
import (
	. "../common"
)

func diameterOfBinaryTree(root *TreeNode) int {
	_, diamter := helper(root)

	return diamter
}

func helper(root *TreeNode) (depth, diameter int) {
	if root == nil {
		return
	}

	leftDepth, leftDia := helper(root.Left)
	righDepth, rightDia := helper(root.Right)

	depth = max(leftDepth, righDepth) + 1
	diameter = max(leftDepth+righDepth, max(leftDia, rightDia))
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
