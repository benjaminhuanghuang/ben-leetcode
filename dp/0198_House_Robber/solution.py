'''
198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
money you can rob tonight without alerting the police.

Hint:
    http://www.cnblogs.com/grandyang/p/4383632.html
    Pickup one or more numbers in a array. The numbers can not be adjacent. Make the sum of the number biggest.

Sample: for nums [3, 2, 1, 5]
dp[0] = 3
dp[1] = 3  because can not rob room[1]
dp[2] = max (dp[0] + nums[2], dp[1])
...
dp[i] = max (dp[i-2] + nums[i], dp[i-1])

'''


# O(n) time, O(n) space
def rob_On(nums):
    size = len(nums)
    # dp [i] means total money when rob room[i]
    if len(nums) <= 0:
        return 0
    dp = [0] * size
    if size:
        dp[0] = nums[0]

    for i in range(1, size):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
    return dp[-1]


# O(n) time, O(1) space
def rob_O1(nums):
    size = len(nums)
    odd, even = 0, 0
    for i in range(size):
        if i % 2:
            odd = max(odd + nums[i], even)
        else:
            even = max(even + nums[i], odd)
    return max(odd, even)
