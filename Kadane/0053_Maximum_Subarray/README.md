# 53. Maximum Subarray

Difficulty: Easy

https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6


Hints:
    nums[i] = max(nums[i - 1] + nums[i], nums[i])
