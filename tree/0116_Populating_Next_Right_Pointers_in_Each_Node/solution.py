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
