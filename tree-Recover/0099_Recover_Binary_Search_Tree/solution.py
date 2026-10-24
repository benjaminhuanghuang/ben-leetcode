'''
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

'''


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    # O(N) space
    def recoverTree_naive(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        list_val = []
        list_node = []
        self.inorder(root, list_val, list_node)
        list_val.sort()
        for i in range(len(list_val)):
            list_node[i].val = list_val[i]
        return root

    # to BST, inorder should be ascending
    def inorder(self, root, list_val, list_node):
        if root:
            self.inorder(root.left, list_val, list_node)
            list_val.append(root.val)
            list_node.append(root)
            self.inorder(root.right, list_val, list_node)

    # http://www.cnblogs.com/zuoyuan/p/3746594.html
    def recoverTree(self, root):
        self.n1 = None
        self.n2 = None
        self.prev = None

        self.FindTwoNodes(root)
        # self.traverse(root)

        self.n1.val, self.n2.val = self.n2.val, self.n1.val

    # http://www.cnblogs.com/zuoyuan/p/3746594.html
    def FindTwoNodes(self, root):
        if root:
            self.FindTwoNodes(root.left)
            if self.prev and self.prev.val > root.val:
                self.n2 = root
                if self.n1 == None:
                    self.n1 = self.prev
            self.prev = root
            self.FindTwoNodes(root.right)

    # http://46aae4d1e2371e4aa769798941cef698.devproxy.yunshipei.com/bcj296050240/article/details/51530803
    def traverse(self, root):
        if root:
            self.traverse(root.left)
            if self.prev:
                if self.n1 == None and self.prev.val > root.val:
                    self.n1 = self.prev
                if self.n1 and self.prev.val > root.val:
                    self.n2 = root
            self.prev = root

            self.traverse(root.right)
