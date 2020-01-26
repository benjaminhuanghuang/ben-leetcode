'''
414. Third Maximum Number

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist,
return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
'''

MIN_INT = -2 ** 31


class Solution(object):
    def thirdMax_my(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_1 = MIN_INT - 1  # for case [1,2,MIN_INT]
        max_2 = MIN_INT - 1
        max_3 = MIN_INT - 1

        for n in nums:
            if n >= max_1:
                if n > max_1:
                    max_3 = max_2  # Note the order!!!
                    max_2 = max_1
                    max_1 = n
            elif n >= max_2:
                if n > max_2:
                    max_3 = max_2
                    max_2 = n
            elif n >= max_3:
                max_3 = n

        if max_3 == MIN_INT - 1:
            return max_1
        return max_3

    def thirdMax_better(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_1 = MIN_INT - 1  # for case [1,2,MIN_INT]
        max_2 = MIN_INT - 1
        max_3 = MIN_INT - 1

        for n in nums:
            if n > max_1:
                max_3 = max_2  # Note the order!!!
                max_2 = max_1
                max_1 = n
            elif max_1> n and n > max_2:
                max_3 = max_2
                max_2 = n
            elif max_2 > n and n > max_3:
                max_3 = n

        if max_3 == MIN_INT - 1:
            return max_1
        return max_3



s = Solution()

n = s.thirdMax([2, 2, 3, 1])
print n
