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