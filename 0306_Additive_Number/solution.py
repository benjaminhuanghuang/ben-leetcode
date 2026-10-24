class Solution(object):
    def isAdditiveNumber(self, nums):
        """
        :type num: str
        :rtype: bool
        """
        if not nums or len(nums) < 3:
            return False
        n = len(nums)
        for i in xrange(1, n):
            for j in xrange(i + 1, n):
                if self.dfs(0, i, j, n, nums):
                    return True
        return False

    def dfs(self, start, first, second, n, num):
        first_num, second_num = num[start:first], num[first:second]

        if (len(first_num) > 1 and first_num[0] == '0') or (len(second_num) > 1 and second_num[0] == '0'):
            return False

        temp_sum = int(first_num) + int(second_num)

        if temp_sum == int(num[second:]) and num[second] != '0':
            return True

        max_len = max(first - start, second - first)

        if second + max_len <= n:
            status = False
            if temp_sum == int(num[second:second + max_len]):
                status = self.dfs(first, second, second + max_len, n, num)
            if not status and second + max_len + 1 <= n and temp_sum == int(num[second:second + max_len + 1]):
                status = self.dfs(first, second, second + max_len + 1, n, num)
            return status
        return False
