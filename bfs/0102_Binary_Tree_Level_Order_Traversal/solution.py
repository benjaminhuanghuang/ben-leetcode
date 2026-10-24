class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if root is None:
            return result

        nodes = [root]
        while len(nodes):
            val = []
            children = []
            for node in nodes:
                val.append(node.val)
                if node.left:
                    children.append(node.left)
                if node.right:
                    children.append(node.right)
            nodes = children
            result.append(val)
        return result


class Solution_my(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        level = [root]
        res = []

        while len(level) > 0:
            next_level = []
            values = []
            for node in level:
                if node:
                    values.append(node.val)
                    next_level.append(node.left)
                    next_level.append(node.right)
            level = next_level
            if values:
                res.append(values)
        return res
