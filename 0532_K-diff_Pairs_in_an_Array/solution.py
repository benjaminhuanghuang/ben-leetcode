class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans = 0
        nums.sort()
        numSet = set()
        sameSet = set()
        if k == 0:
            for num in nums:
                if num in numSet and (not num in sameSet):
                    ans += 1
                    sameSet.add(num)
                numSet.add(num)
        else:
            for num in nums:
                if (not num in numSet) and (num - k) in numSet:
                    ans += 1
                numSet.add(num)
        return ans


nums = [3, 1, 4, 1, 5]
k = 2

s = Solution()
print s.findPairs(nums, k)
