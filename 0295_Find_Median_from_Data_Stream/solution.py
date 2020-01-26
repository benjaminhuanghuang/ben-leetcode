'''
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even,
there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
'''


class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.values = []

    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if not self.values:
            self.values.append(num)
            return

        if num < self.values[0]:
            self.values.insert(0, num)
            return

        if num >= self.values[-1]:
            self.values.append(num)
            return

        l = 0
        r = len(self.values) - 1
        while l < r:
            i = (l + r) >> 1
            if self.values[i] > num:
                r = i
            else:
                l = i + 1
        self.values.insert(l, num)


def findMedian(self):
    """
    Returns the median of current data stream
    :rtype: float
    """
    if len(self.values) == 0:
        return 0

    mid = len(self.values) / 2

    if len(self.values) % 2 == 0:
        return (self.values[mid - 1] + self.values[mid]) / 2.0
    else:
        return self.values[mid]


test = MedianFinder()
# test.addNum(0)
# print test.findMedian()
test.addNum(6)
test.addNum(10)
test.addNum(2)
test.addNum(6)
test.addNum(5)
test.addNum(0)
test.addNum(6)
test.addNum(3)
test.addNum(1)
test.addNum(0)
test.addNum(0)

print test.findMedian()
