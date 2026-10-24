# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    #  Passed at first try
    def connect(self, root):
        if not root:
            return

        nodes = [root]
        while nodes:
            next_nodes = []
            for i in xrange(len(nodes)):
                if nodes[i].left:
                    next_nodes.append(nodes[i].left)
                if nodes[i].right:
                    next_nodes.append(nodes[i].right)
                if i < len(nodes) - 1:
                    nodes[i].next = nodes[i + 1]
                else:
                    nodes[i].next = None
            nodes = next_nodes
