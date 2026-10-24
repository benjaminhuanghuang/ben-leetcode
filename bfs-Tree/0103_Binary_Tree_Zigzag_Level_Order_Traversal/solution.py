class Solution(object):
    # passed at first try
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        left_right = True

        result = []
        level = [root]
        while level:
            level_val = []
            new_level = []
            for n in level:
                level_val.append(n.val)
                if n.left:
                    new_level.append(n.left)
                if n.right:
                    new_level.append(n.right)

            if left_right:
                result.append(level_val)
            else:
                result.append(level_val[::-1])

            left_right = not left_right
            level = new_level
        return result
