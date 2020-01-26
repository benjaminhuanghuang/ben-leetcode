'''
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
'''


class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if not s or not t:
            return True

        if len(s) != len(t):
            return False

        s_dict = {}
        t_dict = {}
        for i in range(len(s)):
            if s[i] in s_dict.keys() and s_dict[s[i]] != t[i]:
                return False
            if t[i] in t_dict.keys() and t_dict[t[i]] != s[i]:
                return False
            s_dict[s[i]] = t[i]
            t_dict[t[i]] = s[i]
        return True

    def isIsomorphic_2(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        sdict = {}
        tdict = {}

        for i, j in zip(s, t):   # good !
            if i not in sdict:
                sdict[i] = j
            if j not in tdict:
                tdict[j] = i
            if sdict[i] != j or tdict[j] != i:
                return False
        return True
