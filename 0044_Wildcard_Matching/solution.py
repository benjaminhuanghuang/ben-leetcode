'''
44. Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "*") -> true
isMatch("aa", "a*") -> true
isMatch("ab", "?*") -> true
isMatch("aab", "c*a*b") -> false

'''


class Solution(object):
    # http://www.jiuzhang.com/solutions/wildcard-matching/
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        n = len(s)
        m = len(p)
        f = [[False] * (m + 1) for i in range(n + 1)]
        f[0][0] = True

        if n == 0 and p.count('*') == m:
            return True

        for i in range(0, n + 1):
            for j in range(0, m + 1):
                if i > 0 and j > 0:
                    f[i][j] |= f[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] in ['?', '*'])

                if i > 0 and j > 0:
                    f[i][j] |= f[i - 1][j] and p[j - 1] == '*'

                if j > 0:
                    f[i][j] |= f[i][j - 1] and p[j - 1] == '*'

        return f[n][m]

    #  http://www.cnblogs.com/zuoyuan/p/3781872.html
    def isMatch_2(self, s, p):
        i_p = i_s = star_match_s = 0
        star_pos_p = -1
        while i_s < len(s):
            if i_p < len(p) and (s[i_s] == p[i_p] or p[i_p] == '?'):
                i_s += 1
                i_p += 1
                continue
            if i_p < len(p) and p[i_p] == '*':
                star_pos_p = i_p
                i_p += 1
                star_match_s = i_s
                continue
            if star_pos_p != -1:
                i_p = star_pos_p + 1
                star_match_s += 1
                i_s = star_match_s
                continue
            return False

        while i_p < len(p) and p[i_p] == '*':
            i_p += 1

        if i_p == len(p):
            return True
        return False


s = Solution()
# print s.isMatch_2("hi", "*?")
print s.isMatch_2("abeeed", "?b*d**")
# print s.isMatch_2("abefcdgiescdfimde", "ab*cd?i*de")
