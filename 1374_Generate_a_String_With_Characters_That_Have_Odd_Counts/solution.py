'''
1374. Generate a String With Characters That Have Odd Counts

Level: Easy

https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts
'''
'''
  Solution: 
'''
class Solution:
    def generateTheString(self, n: int) -> str:
      if n % 2 == 0: 
        return 'a'*(n-1) + 'b'
      else: 
        return 'a'*(n)