'''
409. Longest Palindrome


Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be
built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
'''

import collections


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count_dict = collections.Counter(s)
        res = 0
        hasSingle = False

        for c, count in count_dict.iteritems():
            if count % 2 == 1:
                hasSingle = True
            res += count / 2
        res = res * 2
        if hasSingle:
            res += 1
        return res
