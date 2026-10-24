class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        firstCap = ord(word[0]) <= ord('Z') and ord(word[0]) >= ord('A')
        allCap = True
        allLower = True
        for i in range(1, len(word)):
            c = word[i]
            if ord(c) > ord('Z') or ord(c) < ord('A'):
                allCap = False
            if ord(c) > ord('z') or ord(c) < ord('a'):
                allLower = False

        return (firstCap and allCap) or allLower

    def detectCapitalUse_Better(self, word):
        """
        :type word: str
        :rtype: bool
        """
        return word[1:].islower() or word.islower() or word.isupper()


s = Solution()
print s.detectCapitalUse("USA")
print s.detectCapitalUse("leetcode")
print s.detectCapitalUse("Google")
print s.detectCapitalUse("GooglE")
