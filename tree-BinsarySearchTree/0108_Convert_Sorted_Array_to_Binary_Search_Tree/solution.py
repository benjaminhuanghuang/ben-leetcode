'''
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

balanced means the difference of the height of left sub tree and the right sub tree <=1
'''

from data_structure.tree_node import TreeNode


class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        return self.helper(nums, 0, len(nums) - 1)

    def helper(self, nums, left, right):
        if left == right:
            return nums[left]
        mid = left + ((right - left) >> 1)  # Note! + has higher priority than >>
        root = TreeNode(nums[mid])
        root.left = self.helper(nums, left, mid - 1)
        root.right = self.helper(nums, mid + 1, right)
        return root


s = Solution()
print s.sortedArrayToBST([0])
