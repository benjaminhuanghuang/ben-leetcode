'''
306. Additive Number

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers,
each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
'''


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
