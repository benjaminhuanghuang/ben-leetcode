/*
79. Word Search
https://leetcode.com/problems/word-search/
*/

function exist(board: string[][], word: string): boolean {
  const rows = board.length;
  const cols = board[0].length;
  const visited = Array.from({ length: rows }, () => Array(cols).fill(false));
  const directions = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];

  const dfs = (row: number, col: number, index: number): boolean => {
    if (index === word.length) {
      return true;
    }
    if (
      row < 0 ||
      row >= rows ||
      col < 0 ||
      col >= cols ||
      visited[row][col] ||
      board[row][col] !== word[index]
    ) {
      return false;
    }

    visited[row][col] = true;
    for (const [dx, dy] of directions) {
      if (dfs(row + dx, col + dy, index + 1)) {
        return true;
      }
    }
    visited[row][col] = false;

    return false;
  };

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (dfs(i, j, 0)) {
        return true;
      }
    }
  }

  return false;
}
