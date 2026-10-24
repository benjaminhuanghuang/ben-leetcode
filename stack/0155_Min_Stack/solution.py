'''
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
'''

import sys


class MinStack_my(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.values = []
        self.mins = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.values.append(x)
        if len(self.mins) > 0:
            self.mins.append(min(self.mins[-1], x))
        else:
            self.mins.append(x)

    def pop(self):
        """
        :rtype: void
        """
        self.values.pop()
        self.mins.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.values[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.mins[-1]


class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.stack1.append(x)
        if len(self.stack2) == 0 or x <= self.stack2[-1]:
            self.stack2.append(x)

    def pop(self):
        """
        :rtype: void
        """
        top = self.stack1[-1]
        self.stack1.pop()
        if top == self.stack2[-1]:
            self.stack2.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack1[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.stack2[-1]
