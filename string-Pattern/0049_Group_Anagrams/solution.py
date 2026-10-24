class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dict = {}
        for word in strs:
            sortedword = ''.join(sorted(word))
            dict[sortedword] = [word] if sortedword not in dict else dict[sortedword] + [word]

        res = []
        for item in dict:
            res.append(dict[item])
        return res


input = ["eat", "tea", "tan", "ate", "nat", "bat"]
s = Solution()
print s.groupAnagrams(input)
