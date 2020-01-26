'''
260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

'''


class Solution(object):
    # http://blog.neoshell.moe/leetcode260.html
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a_xor_b = 0;
        for i in xrange(len(nums)):
            a_xor_b ^= nums[i]

        # ! Key point
        # -a_xor_b = ~a_xor_b + 1
        a_xor_b &= -a_xor_b  # Get the last set (1) bit, that is the last difference bit those two number have

        result = [0] * 2
        for n in nums:
            if (n & a_xor_b) == 0:
                result[0] ^= n
            else:
                result[1] ^= n

        return result


nums = [1, 2, 1, 3, 2, 5]
s = Solution()

print s.singleNumber(nums)


print ~3 +1