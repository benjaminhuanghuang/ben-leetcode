// https://leetcode.com/problems/symmetric-tree/
package leetcode0101

import (
	. "../common"
)

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isMirror(root.Left, root.Right)
}

func isMirror(t1 *TreeNode, t2 *TreeNode) bool {
	if t1 == nil && t2 == nil {
		return true
	}
	if t1 == nil || t2 == nil {
		return false
	}

	if t1.Val != t2.Val {
		return false
	}

	return isMirror(t1.Left, t2.Right) && isMirror(t1.Right, t2.Left)
}
