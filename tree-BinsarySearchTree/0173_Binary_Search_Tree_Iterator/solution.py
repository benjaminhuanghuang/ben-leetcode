'''
173. Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


'''


# http://yuanhsh.iteye.com/blog/2173429
class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        self.push_left(root)

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack) > 0

    def push_left(self, node):
        while node:
            self.stack.append(node)
            node = node.left

    # Return the next smallest number in the BST.
    def next(self):
        """
        :rtype: int
        """
        smallest_node = self.stack.pop()
        self.push_left(smallest_node.right)
        return smallest_node.val


s = BSTIterator()

