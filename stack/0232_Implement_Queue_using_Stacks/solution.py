'''
232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Notes:
    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty
operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque
(double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


reference
    https://leetcode.com/articles/implement-queue-using-stacks/

'''


class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []

    def push(self, x):
        self.stack.append(x)

    def pop(self):
        swap = []
        while self.stack:
            swap.append(self.stack.pop())
        val = swap.pop()
        while swap:
            self.stack.append(swap.pop())
        return val

    def peek(self):
        return self.stack[0]

    def empty(self):
        return len(self.stack) <= 0


q = Queue()
q.push(1)
q.pop()

print q.empty()