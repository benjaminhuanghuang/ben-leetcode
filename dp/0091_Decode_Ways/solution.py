'''
91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
'''


class Solution(object):
    # if s[i] = 0, dp[i] = dp[i-2]
    # if s[i] !=0, dp[i] = dp[i-1]
    # if 10 < int(s[i - 2] + s[i - 1])<=26, dp[i] = dp[i-1] + dp[i-2]
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == "" or s[0] == '0':
            return 0
        dp = [1, 1]
        for i in range(2, len(s) + 1):
            if 10 <= int(s[i - 2:i]) <= 26 and s[i - 1] != '0':
                dp.append(dp[i - 1] + dp[i - 2])
            elif int(s[i - 2:i]) == 10 or int(s[i - 2:i]) == 20:
                dp.append(dp[i - 2])
            elif s[i - 1] != '0':
                dp.append(dp[i - 1])
            else:
                return 0
        return dp[len(s)]

    def numDecodings_2(self, s):
        if len(s) == 0 or s[0] == '0':
            return 0
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1
        for i in range(1, n):
            if s[i] != '0':
                dp[i + 1] = dp[i]
            if int(s[i - 1] + s[i]) >= 10 and int(s[i - 1] + s[i]) <= 26:
                dp[i + 1] += dp[i - 1];
        return dp[n]

    def numDecodings_3(self, s):
        n = len(s)

        if not s or n == 0:
            return 0
        dp = [0] * (n + 1)
        dp[0] = 1  # store the number of two digits
        if s[0] != "0":
            dp[1] = 1

        for i in range(2, n + 1):
            if s[i - 1] != '0':
                dp[i] = dp[i - 1]
            two = int(s[i - 2] + s[i - 1])
            if two >= 10 and two <= 26:
                dp[i] += dp[i - 2]
        return dp[n]


s = Solution()
print s.numDecodings("100")