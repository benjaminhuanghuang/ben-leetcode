'''
398. Random Pick Index

Given an array of integers with possible duplicates, randomly output the index of a given target number.
You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);

'''
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
