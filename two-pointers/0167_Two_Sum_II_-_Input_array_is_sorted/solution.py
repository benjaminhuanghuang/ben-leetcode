'''
167. Two Sum II - Input array is sorted [mastered]

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a
specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1
must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
'''


class Solution(object):
    def twoSum_niave(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not numbers or len(numbers) < 2:
            return [-1, -1]

        length = len(numbers)
        for i in xrange(length):
            for j in xrange(i + 1, length):
                if numbers[i] + numbers[j] == target:
                    return [i + 1, j + 1]
        return [-1, -1]

    # O(n log n) runtime, O(1) space
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not numbers or len(numbers) < 2:
            return [-1, -1]

        left = 0
        right = len(numbers) - 1

        while left < right:
            sum = numbers[left] + numbers[right]
            if sum == target:
                return [left + 1, right + 1]
            elif sum < target:
                left += 1
            else:
                right -= 1

        return [-1, -1]
