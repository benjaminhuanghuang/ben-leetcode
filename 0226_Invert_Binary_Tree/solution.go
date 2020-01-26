// https://leetcode.com/problems/invert-binary-tree
package leetcode0226
/*
	
 */

 func invertTree(root *TreeNode) *TreeNode {
		if root == nil {
			return nil
		}

		temp := invertTree(root.Left)
		root.Left = invertTree(root.Right)
		root.Right =temp
		return right
}