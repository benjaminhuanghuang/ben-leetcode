class Solution(object):
    # http://www.tianmaying.com/tutorial/LC72
    # f[i][j] = the distance between w1[0 to i] and w2[0 to j]
    #   if word1[i] == word2[j]:
    #       f[i][j] == f[i-1][j-1]
    #   else:
    #       f[i][j] = f[i-1][j-1] + 1   # replace word1[i] with word2[j]
    #       f[i][j] = f[i-1][j]+1       # word1[i] append word2[j]
    #       f[i][j] = f[i-1][j]+1       # word1[i] remove word2[j]
    #   f[i][0] = i  # delete word1
    #   f[0][i] = i  # append word2
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1) + 1;
        n = len(word2) + 1
        dp = [[0 for i in range(n)] for j in range(m)]
        for i in range(n):
            dp[0][i] = i
        for i in range(m):
            dp[i][0] = i

        for i in range(1, m):
            for j in range(1, n):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1] + 1, dp[i - 1][j]))
        return dp[m - 1][n - 1]
