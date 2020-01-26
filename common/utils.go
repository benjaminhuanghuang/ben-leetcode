package common

import "fmt"

func BuildList(nums ...int) *ListNode {
	dummy := ListNode{}
	p := &dummy

	for _, num := range nums {
		p.Next = &ListNode{Val: num}
		p = p.Next
	}

	return dummy.Next
}

func IsSameList(l1 *ListNode, l2 *ListNode) bool {
	for l1 != nil && l2 != nil {
		if l1.Val != l2.Val {
			return false
		}
		l1 = l1.Next
		l2 = l2.Next
	}

	if l1 == nil && l2 == nil {
		return true
	}

	return false
}

func PrintList(message string, l *ListNode) {
	fmt.Print(message)
	for l != nil {
		fmt.Printf(" %d", l.Val)
		l = l.Next
	}
	fmt.Print("\n")
}

const NIL_NODE = -10000

func BuildTreeInLevelOrder(nums []int) *TreeNode {
	var root *TreeNode
	root = insertLevelOrder(nums, root, 0)
	return root
}

func insertLevelOrder(nums []int, root *TreeNode, startPos int) *TreeNode {
	if startPos < len(nums) {
		if nums[startPos] == -10000 {
			return nil
		}

		temp := &TreeNode{Val: nums[startPos]}
		root = temp

		// insert left child
		root.Left = insertLevelOrder(nums, root.Left, 2*startPos+1)

		// insert right child
		root.Right = insertLevelOrder(nums, root.Right, 2*startPos+2)
	}
	return root
}
