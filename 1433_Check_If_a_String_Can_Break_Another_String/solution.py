'''
1433. Check If a String Can Break Another String

Level: Medium

https://leetcode.com/problems/check-if-a-string-can-break-another-string
'''
'''
  Solution: 
'''
class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
      l1 = sorted(list(s1))
      l2 = sorted(list(s2))

      res = True
      for i,j in zip(l1,l2):
          if i < j:
              res = False
              break
      if res : return res

      res = True
      for i,j in zip(l1,l2):
          if i > j:
              res = False
              break

      return res