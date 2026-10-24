# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # Time Limit Exceeded! if put max(self.count_dict.values()) in to
    #   [k for k, v in self.count_dict.iteritems() if v == maxn]
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return[]
        self.count_dict = {}
        self.traversal(root)
        maxn = max(self.count_dict.values())
        return [k for k, v in self.count_dict.iteritems() if v == maxn]

    def traversal(self, node):
        if not node:
            return

        self.count_dict[node.val] = self.count_dict.get(node.val, 0) + 1
        self.traversal(node.left)
        self.traversal(node.right)


s = Solution()
print s.findMode(TreeNode(0))
