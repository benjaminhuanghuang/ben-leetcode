# http://www.cnblogs.com/grandyang/p/6399855.html
class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        for num in findNums:
            next_greater = -1
            for i in range(len(nums)):
                if nums[i] == num:
                    break

            for j in range(i + 1, len(nums)):
                if nums[j] > num:
                    next_greater = nums[j]
                    break

            res.append(next_greater)
        return res

    def nextGreaterElement_better(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        dict = {}
        for idx, num in enumerate(nums):
            dict[num] = idx

        for num in findNums:
            next_greater = -1
            start = dict[num]
            for i in range(start + 1, len(nums)):
                if nums[i] > num:
                    next_greater = nums[i]
                    break

            res.append(next_greater)
        return res


s = Solution()
print s.nextGreaterElement_better([2], [1, 3, 4, 2])
