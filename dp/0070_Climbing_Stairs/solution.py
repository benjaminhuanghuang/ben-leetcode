'''
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Hit:
step[i]  = step[i-1] then climb 1 or step[i-2] then climb 2

'''


# recursion is slow Time Limit Exceeded
def climb_stairs(n):
    if n == 1 or n <= 0:
        return 1
    return climb_stairs(n - 1) + climb_stairs(n - 2)


print climb_stairs(35)


class Solution_my(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1 or n <= 0:
            return 1
        dp = [0 for i in range(n + 1)]
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]


class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 1:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2
        cache = [0 for i in range(n)]
        cache[0] = 1
        cache[1] = 2
        for i in range(2, n):
            cache[i] = cache[i - 1] + cache[i - 2]
        return cache[n - 1]

    def climbStairs_2(self, n):
        """
        :type n: int
        :rtype: int
        """
        fn_1 = 2
        fn_2 = 1

        if n < 1:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2
        fn = fn_1 + fn_2
        for i in range(3, n + 1):
            fn = fn_1 + fn_2
            fn_2 = fn_1
            fn_1 = fn

        return fn


solu = Solution()
print solu.climbStairs(10)
