'''
1015. Smallest Integer Divisible by K

Level: Medium

https://leetcode.com/problems/smallest-integer-divisible-by-k
'''
'''
  Solution: 
'''
class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0:
            return -1
        g = 0
        for i in range(1, K+1):
            g = (g * 10 + 1) % K
            if g == 0:
                return i
        return -1  

        