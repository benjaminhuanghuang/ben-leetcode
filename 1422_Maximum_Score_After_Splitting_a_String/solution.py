'''
1422. Maximum Score After Splitting a String

Level: Easy

https://leetcode.com/problems/maximum-score-after-splitting-a-string
'''
'''
  Solution: 
'''
class Solution:
    def maxScore(self, s: str) -> int:
        count_1 = s.count('1')
        res = 0
        sub_count_1 = 0
        sub_count_0 = 0
        for i in s[:-1]:
            if i == '0':
                sub_count_0 += 1
            else:
                sub_count_1 += 1

            res = max(res,sub_count_0 + (count_1 - sub_count_1))

        return res