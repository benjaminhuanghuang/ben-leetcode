'''
520. Detect Capital

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.


'''


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
