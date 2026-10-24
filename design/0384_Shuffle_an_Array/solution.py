import random


class Solution(object):
    def __init__(self, nums):
        """

        :type nums: List[int]
        :type size: int
        """
        self.nums = nums[:]
        self.backup = nums[:]

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.nums = self.backup[:]
        return self.nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        for x in range(len(self.nums)):
            y = random.randint(0, x)  # 0 <= y <=x
            self.nums[x], self.nums[y] = self.nums[y], self.nums[x]
        return self.nums
