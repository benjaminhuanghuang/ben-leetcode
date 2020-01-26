'''
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


'''


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
