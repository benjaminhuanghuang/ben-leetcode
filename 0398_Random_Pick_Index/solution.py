import random


# passed at first try!
class Solution(object):
    def __init__(self, nums):
        """

        :type nums: List[int]
        :type numsSize: int
        """
        self.nums = nums
        self.dict = {}
        for i in xrange(len(nums)):
            if nums[i] in self.dict:
                self.dict[nums[i]].append(i)
            else:
                self.dict[nums[i]] = [i]

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        # You can assume that the given target number must exist in the array.
        indexes = self.dict[target]
        return indexes[random.randint(0, len(indexes) - 1)]


s = Solution([1, 2, 3, 3, 3])
print s.pick(3)
print s.pick(1)
