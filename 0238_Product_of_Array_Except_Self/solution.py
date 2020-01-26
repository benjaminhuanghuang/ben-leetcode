'''
238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)


Hints:
Create an array to put the product.
The first pass is to get the product before each number and the second pass to get product after each.

'''


class Solution(object):
    # O(n) time O(1) space
    # http://www.cnblogs.com/tjuloading/p/4651382.html
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res = [1] * n
        l = r = 1

        # res[0] = res[0]*1
        # res[0] = res[1]*res[0]
        # res[i] = nums[0]*nums[1]...*nums[i-1]
        for i in range(1, n):
            l *= nums[i - 1]
            res[i] *= l

        # res[i] = res[i]*nums[i+1]*...*nums[len-1]
        for i in range(n - 2, -1, -1):
            r *= nums[i + 1]
            res[i] *= r

        return res
