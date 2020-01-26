'''
76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

'''

import collections


class Solution(object):
    # http://www.tangjikai.com/algorithms/leetcode-76-minimum-window-substring
    def minWindow(self, s, t):
        res = ''
        window = []
        dic = collections.defaultdict(list)
        tCount = collections.Counter(t)

        for i, c in filter(lambda x: x[1] in t, enumerate(s)):
            if len(dic[c]) == tCount[c]:
                window.remove(dic[c].pop(0))

            dic[c].append(i)
            window.append(i)

            if len(window) == len(t) and (res == '' or window[-1] - window[0] < len(res)):
                res = s[window[0]: window[-1] + 1]

        return res

    # http://blog.sina.com.cn/s/blog_eb52001d0102v2il.html
    def minWindow_9(self, source, target):
        """
        :type source: str
        :type target: str
        :rtype: str
        """

        if (target == ""):
            return ""
        d_char_in_target, d_char_found = {}, dict.fromkeys(target, 0)
        for c in target:
            d_char_in_target[c] = d_char_in_target.get(c, 0) + 1

        left, right, cont = 0, 0, 0
        ans = ""
        while right < len(source):
            if source[right] in d_char_found:
                if d_char_found[source[right]] < d_char_in_target[source[right]]:
                    cont += 1
                d_char_found[source[right]] += 1

            if cont == len(target):   # find all char of target in source
                while left < right:
                    if source[left] in d_char_found:
                        if d_char_found[source[left]] == d_char_in_target[source[left]]:
                            break
                        d_char_found[source[left]] -= 1
                    left += 1

                if ans == '' or right - left < len(ans):
                    ans = source[left:right + 1]
                d_char_found[source[left]] -= 1
                left += 1
                cont -= 1
            right += 1
        return ans


source = "ADOBECODEBANC"
target = "AABN"

s = Solution()
print s.minWindow_9(source, target)
