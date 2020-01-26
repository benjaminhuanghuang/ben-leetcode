'''
199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
'''

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
