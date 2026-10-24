from collections import Counter


class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """

        bull = 0

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bull += 1

        sa = Counter(secret)
        sb = Counter(guess)

        cow = sum((sa & sb).values()) - bull

        return str(bull) + 'A' + str(cow) + 'B'


secret = '7810'
guess = '1178'

s = Solution()
print s.getHint(secret, guess)
