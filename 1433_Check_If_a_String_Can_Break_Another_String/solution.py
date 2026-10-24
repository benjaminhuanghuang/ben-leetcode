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