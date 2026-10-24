class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        ret = 0
        g = sorted(g, reverse=True)
        s = sorted(s, reverse=True)
        i_g = 0
        i_s = 0

        while (i_g < len(g) and i_s < len(s)):
            if (g[i_g] <= s[i_s]):
                ret += 1
                i_g += 1
                i_s += 1
            else:
                i_g += 1

        return ret


s = Solution()
ret = s.findContentChildren([10, 9, 8, 7], [5, 6, 7, 8])
print ret
