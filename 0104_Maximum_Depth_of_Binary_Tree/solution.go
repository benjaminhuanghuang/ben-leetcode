// https://leetcode.com/problems/maximum-depth-of-binary-tree
package leetcode0104
import (
	. "../common"
)
/*
	
 */

 func maxDepth(root *TreeNode) int {
		if root == nil{
			return 0
		}
		
		leftDepth := maxDepth(root.Left)
		rightDepth := maxDepth(root.Right)

		if leftDepth > rightDepth{
			return leftDepth + 1
		}
		return rightDepth + 1
}