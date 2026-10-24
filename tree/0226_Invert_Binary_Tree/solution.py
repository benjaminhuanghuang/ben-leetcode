'''
226. Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

https://leetcode.com/problems/invert-binary-tree/
Google: 90% of our engineers use the software you wrote (Homebrew),
but you can't invert a binary tree on a whiteboard so fuck off.

'''
class Solution_my(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root:
            self.invertTree(root.left)
            self.invertTree(root.right)

            root.left, root.right = root.right, root.left
        return root

# Recursion version
def invert_binary_tree(root):
    if root is None:
        return None

    if root.left:
        invert_binary_tree(root.left)
    if root.right:
        invert_binary_tree(root.right)
    root.left, root.right = root.right, root.left
    return root


# Iteration version
class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is None:
            return None
        queue = [root]
        while queue:
            front = queue.pop(0)
            if front.left:
                queue.append(front.left)
            if front.right:
                queue.append(front.right)
            front.left, front.right = front.right, front.left
        return root
