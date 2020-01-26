'''
451. Sort Characters By Frequency

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
'''

import collections


class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        count_dict = collections.Counter(s)
        sorted_keys = sorted(count_dict, key=lambda x: count_dict[x], reverse=True)
        ans = []
        for k in sorted_keys:
            ans += [k] * count_dict[k]
        return "".join(ans)


s = Solution()
s.frequencySort("adddbddd")
