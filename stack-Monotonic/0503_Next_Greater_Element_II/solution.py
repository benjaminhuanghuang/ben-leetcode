class Solution(object):
    def nextGreaterElements_brute_force(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        length = len(nums)

        for start, num in enumerate(nums):
            next_greater = -1
            for i in range(length - 1):
                if nums[(start + i + 1) % length] > num:
                    next_greater = nums[(start + i + 1) % length]
                    break
            res.append(next_greater)

        return res

    # http://blog.csdn.net/xiaocong1990/article/details/54974704
    # http://massivealgorithms.blogspot.com/2017/02/leetcode-503-next-greater-element-ii.html
    # use stack to keep the indexes of the decreasing subsequence
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        res = [-1 for i in range(length)]
        stack = []

        for i in range(2 * length):
            j = i % length
            while (len(stack) > 0 and nums[stack[-1]] < nums[j]):
                res[stack[-1]] = nums[j]
                stack.pop(-1)
            stack.append(j)

        return res


s = Solution()
print s.nextGreaterElements([1, 2, 1])
print s.nextGreaterElements([])
print s.nextGreaterElements([1])
print s.nextGreaterElements([])
