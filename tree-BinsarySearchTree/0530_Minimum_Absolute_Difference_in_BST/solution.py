# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    # min among following value:
    #   root.val - max_of_left_sub_tree
    #   min_diff_of_left_sub_tree
    #   min_of_right_sub_tree - root.val
    #   min_diff_of_right_sub_tree
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        left, right = root.left, root.right
        ans = 0x7FFFFFFF
        if left:
            while left.right:
                left = left.right
            ans = min(root.val - left.val, self.getMinimumDifference(root.left))

        if right:
            while right.left:
                right = right.left
            ans = min(ans, right.val - root.val, self.getMinimumDifference(root.right))

        return ans
