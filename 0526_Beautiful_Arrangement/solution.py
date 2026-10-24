class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        cache = dict()

        def solve(idx, nums):
            if not nums:
                return 1
            key = idx, tuple(nums)
            if key in cache:
                return cache[key]
            ans = 0
            for i, n in enumerate(nums):
                if n % idx == 0 or idx % n == 0:
                    ans += solve(idx + 1, nums[:i] + nums[i + 1:])
            cache[key] = ans
            return ans

        return solve(1, range(1, N + 1))


# DFS Solution
# http://massivealgorithms.blogspot.com/2017/02/leetcode-526-beautiful-arrangement.html
# http://www.itwendao.com/article/detail/268726.html

class Solution_DFS(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        used = [False for _ in range(N)]

        return self.backtrack(used, 0)

    def backtrack(self, used, curIndex):
        if curIndex == len(used):
            return 1  # why return 1 here?
        sum = 0
        for i in range(len(used)):
            if (not used[i] and
                    ((i + 1) % (curIndex + 1) == 0 or (curIndex + 1) % (i + 1) == 0)):
                used[i] = True
                sum += self.backtrack(used, curIndex + 1)
                used[i] = False
        return sum


s = Solution()

print s.countArrangement(6)

s = Solution_DFS()

print s.countArrangement(6)
