'''
485. Max Consecutive Ones [Easy]

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
'''


class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_len = 0
        len = 0
        for n in nums:
            if n == 1:
                len += 1
            else:
                max_len = max(len, max_len)
                len = 0
        max_len = max(len, max_len)
        return max_len


input[1, 1, 0, 1, 1, 1]
