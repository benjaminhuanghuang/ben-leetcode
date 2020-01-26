'''
455. Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most
one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content
with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will
be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.
'''


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
