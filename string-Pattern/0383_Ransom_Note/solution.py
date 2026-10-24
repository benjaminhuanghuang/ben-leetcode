import collections


class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        char_count_dict = collections.Counter(magazine)
        for char in ransomNote:
            char_count_dict[char] -= 1
            if char_count_dict[char] < 0:
                return False
        return True

    def canConstruct_my(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        count_dict = collections.Counter(magazine)
        for c in ransomNote:
            if count_dict[c] < 1:
                return False
            count_dict[c] -= 1
        return True
