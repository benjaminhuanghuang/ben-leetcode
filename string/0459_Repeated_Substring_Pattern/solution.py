class Solution(object):
    def repeatedSubstringPattern(self, str):
        """
        :type str: str
        :rtype: bool
        """
        length = len(str)
        for i in range(len(str) / 2):
            sub = str[0:i + 1]
            tmp = sub * (length / (i + 1))
            if tmp == str:
                return True
        return False
