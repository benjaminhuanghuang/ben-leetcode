import random

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        if not self.head:
            return None
        answer = count = 0
        head = self.head
        while head:
            if random.randint(0, count) == 0:
                answer = head.val
                break
            head = head.next
            count += 1
        return answer



s = Solution(None)
print s.getRandom()