'''
116. Populating Next Right Pointers in Each Node

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
'''


class Solution(object):
    #  Pass at first try!
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """

        if root is None:
            return

        stack = [root]
        while len(stack) > 0:
            new_level = []
            for i in xrange(len(stack) - 1):
                stack[i].next = stack[i + 1]
                if stack[i].left:
                    new_level.append(stack[i].left)
                if stack[i].right:
                    new_level.append(stack[i].right)

            stack[-1].next = None
            if stack[-1].left:
                new_level.append(stack[-1].left)
            if stack[-1].right:
                new_level.append(stack[-1].right)
            stack = new_level
