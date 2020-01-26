'''
128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

'''


class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dict = {x: False for x in nums}  # False means not visited
        maxLen = -1

        for i in dict:
            if dict[i] == False:
                curr = i + 1
                lenright = 0
                while curr in dict:
                    lenright += 1
                    dict[curr] = True
                    curr += 1
                curr = i - 1
                lenleft = 0
                while curr in dict:
                    lenleft += 1
                    dict[curr] = True
                    curr -= 1
                maxLen = max(maxLen, lenleft + 1 + lenright)
        return maxLen

    def longestConsecutive_better(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        nums.sort()
        last_num = nums[0]
        ans = 1
        tmp = 1
        for n in nums:
            if(n - last_num == 0):
                continue
            elif(n - last_num == 1):  # consecutive
                tmp += 1
            else:
                if tmp > ans:
                    ans = tmp
                tmp = 1
            last_num = n
        if tmp > ans:
            ans = tmp
        return ans
input = [100, 4, 200, 1, 3, 2]
s = Solution()
print s.longestConsecutive(input)