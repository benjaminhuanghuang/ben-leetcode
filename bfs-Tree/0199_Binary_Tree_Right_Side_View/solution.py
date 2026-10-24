class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        level = [root]
        result = []
        while len(level) > 0:
            result.append(level[-1].val)
            new_level = []
            for item in level:
                if item.left:
                    new_level.append(item.left)
                if item.right:
                    new_level.append(item.right)
            level = new_level

        return result
