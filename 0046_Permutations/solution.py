'''
46. Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

'''


class Solution(object):
    def permute_bad(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        for n in nums:
            for r in result:
                result.remove(r)
                for i in xrange(len(r)):
                    newone = r.insert(i, n)
                    result.append(newone)
            else:
                result.append([n])
        return result

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 1:
            return [nums]

        res = []
        for i, x in enumerate(nums):
            for elem in self.permute(nums[:i] + nums[i + 1:]):
                res.append([x] + elem)
                # res.append(elem.append(x)) # elem can be  None

        return res


s = Solution()
print s.permute([1, 2, 3])
