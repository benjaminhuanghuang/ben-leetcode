# coding: utf-8

'''
152. Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
'''

'''
http://bangbingsyb.blogspot.com/2014/11/leetcode-maximum-product-subarray.html
Maximum Subarray那题的变种。由于正负得负，负负得正, 以A[i]结尾的max product subarray同时取决于
以A[i-1]结尾的max / min product subarray以及A[i]本身。因此，对每个i，需要记录min/max product两个状态：

max_product[i] = max(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i])
min_product[i] = min(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i])

'''


class Solution(object):
    # temp = positive
    # positive = max(num, positive * num, negative * num)
    # negative = min(num, temp * num, negative * num)
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        positive, negative = nums[0], nums[0]
        result = nums[0]
        for num in nums[1:]:
            # positive = max(num, positive * num, negative * num)
            # negative = min(num, positive * num, negative * num)
            positive, negative = max(num, positive * num, negative * num), min(num, positive * num, negative * num)
            result = max(result, positive)
        return result

    def maxProduct_2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_prod, min_prod = nums[0], nums[0]
        result = nums[0]
        for num in nums[1:]:
            # positive = max(num, positive * num, negative * num)
            # negative = min(num, positive * num, negative * num)
            tmp = max_prod
            max_prod = max(num, max_prod * num, min_prod * num)
            min_prod = min(num, tmp * num, min_prod * num)
            result = max(result, max_prod)
        return result


s = Solution()
print s.maxProduct([-4, -3, -2])
