class Solution(object):
    # passed on first try
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i_s = 0
        len_s = len(s)
        while i_s < len_s:
            c_s = s[i_s]
            match_index = t.find(c_s)
            if match_index == -1:
                return False
            t = t[match_index + 1:]
            i_s += 1
        return True


s = "leeeeetcode"
t = "leeeeetcode"
solution = Solution()
print solution.isSubsequence(s, t)
