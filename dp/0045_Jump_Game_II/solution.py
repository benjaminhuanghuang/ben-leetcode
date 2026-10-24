'''
45. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

'''


class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]
        for i in range(len(nums) - 1):
            while (i + nums[i] >= len(dp) and len(dp) < len(nums)):
                dp.append(dp[i] + 1)
        return dp[-1]

    # We use "last" to keep track of the maximum distance that has been reached
    # by using the minimum steps "ret", whereas "curr" is the maximum distance
    # that can be reached by using "ret+1" steps. Thus,curr = max(i+A[i]) where 0 <= i <= last.
    def jump_2(self, A):
        ret = 0
        last = 0
        curr = 0
        for i in range(len(A)):
            if i > last:
                last = curr
                ret += 1
            curr = max(curr, i + A[i])
        return ret

    # https://www.hrwhisper.me/leetcode-jump-game/
    def jump_3(self, A):
        # curReach is the max distance currently
        #
        curReach, lastReach, cnt, Len = 0, 0, 0, len(A)
        for i in range(0, Len):
            if lastReach < i:
                lastReach = curReach
                cnt += 1
            curReach = max(curReach, A[i] + i)
        return cnt


input = [2, 3, 1, 1, 4]

s = Solution()
print s.jump(input)
