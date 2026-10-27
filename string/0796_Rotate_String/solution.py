'''
  Solution: A 经过若干次旋转能变成 B -> 等价于长度相等且 B 是 A+A 的子串
'''
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        return len(A) == len(B) and B in A + A
