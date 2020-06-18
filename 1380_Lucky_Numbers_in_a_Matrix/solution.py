'''
1380. Lucky Numbers in a Matrix

Level: Easy

https://leetcode.com/problems/lucky-numbers-in-a-matrix
'''
'''
  Solution: 
'''
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        min_n = {min(rows) for rows in matrix}
        # unpacking operator *
        max_n = {max(columns) for columns in zip(*matrix)} 
        
        return list(min_n & max_n)