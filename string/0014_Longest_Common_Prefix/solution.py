'''
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
'''


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) <= 1:
            return strs[0] if len(strs) == 1 else ""

        end = 0
        min_len = min([len(s) for s in strs])
        
        while end < min_len:
            for i in range(1, len(strs)):
                if strs[i][end] != strs[i - 1][end]:
                    return strs[0][:end]
            end = end + 1
        return strs[0][:end]
