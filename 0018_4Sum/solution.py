'''
18. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

#https://www.hrwhisper.me/leetcode-2-sum-3-sum-4-sum-3-sum-closest-k-sum/
'''

import collections


class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        dic = collections.defaultdict(set)
        res = set()
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                sum = nums[i] + nums[j]
                for half in dic[target - sum]:
                    res.add(tuple(list(half) + [nums[i], nums[j]]))

            for j in range(i):
                dic[nums[i] + nums[j]].add((nums[j], nums[i]))

        return list(res)


    def fourSum_error(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        dic = collections.defaultdict(set)
        res = set()
        n = len(nums)

        for i in range(n):
            for j in range(i+1, n):
                dic[nums[i] + nums[j]].add((nums[j], nums[i]))
            for j in range(i+1, n):
                sum = nums[i] + nums[j]
                for other_two_nums in dic[target -sum]:
                    res.add(list(other_two_nums)+[nums[i], nums[j]])   #Line 19: TypeError: unhashable type: 'list'

        return list(res)