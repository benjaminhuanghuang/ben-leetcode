'''
  Solution:
'''
from typing import List


class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        # bin return the binary string
        return sorted(arr, key=lambda n: (bin(n).count('1'), n))
