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
