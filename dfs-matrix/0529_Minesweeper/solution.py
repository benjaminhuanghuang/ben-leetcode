'''
529. Minesweeper

Level: Medium

https://leetcode.com/problems/minesweeper
'''
'''
  Solution: 
'''
class Solution:
  def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
    m, n = len(board), len(board[0])
    cx, cy = click[1], click[0] 
    q = [(cx, cy)]
    while q:
      q2 = []
      for x, y in q:        
        if board[y][x] != 'E': continue
        c = 0
        for tx in range(x - 1, x + 2):
          for ty in range(y - 1, y + 2):
            if 0 <= tx < n and 0 <= ty < m and board[ty][tx] == 'M':
              c += 1
        if c > 0:
          board[y][x] = chr(ord('0') + c)
          continue
        board[y][x] = 'B'
        for tx in range(x - 1, x + 2):
          for ty in range(y - 1, y + 2):
            if 0 <= tx < n and 0 <= ty < m and board[ty][tx] == 'E':
              q2.append((tx, ty))              
      q = q2
    if board[cy][cx] == 'M': board[y][x] = 'X'
    return board