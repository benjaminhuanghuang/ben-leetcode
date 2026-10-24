'''
384. Shuffle an Array [mastered]

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
'''
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
