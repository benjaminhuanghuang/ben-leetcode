'''
383. Ransom Note
Given an arbitrary ransom note string and another string containing letter from all the magazines, write a function
that will return true if the ransom note can be constructed from the magazine; otherwise, it will return false

Each letter in the magazine string can only be used once in your ransom note.


Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
'''

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
