/*
289. Game of Life
https://leetcode.com/problems/game-of-life/
*/

/*
Time Complexity: O(m*n)
Space Complexity: O(1)

https://www.youtube.com/watch?v=juGxbF-eadU
*/
function gameOfLife(board: number[][]): void {
  const rows = board.length;
  const cols = board[0].length;
  const directions = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
    [1, 1],
    [1, -1],
    [-1, 1],
    [-1, -1],
  ];

  const countLiveNeighbors = (row: number, col: number): number => {
    let count = 0;
    for (const [dx, dy] of directions) {
      const newRow = row + dx;
      const newCol = col + dy;
      if (
        newRow >= 0 &&
        newRow < rows &&
        newCol >= 0 &&
        newCol < cols &&
        (board[newRow][newCol] === 1 || board[newRow][newCol] === 2)
      ) {
        count++;
      }
    }

    return count;
  };

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      const liveNeighbors = countLiveNeighbors(i, j);
      if (board[i][j] === 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
        board[i][j] = 2;
      } else if (board[i][j] === 0 && liveNeighbors === 3) {
        board[i][j] = 3;
      }
    }
  }

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      board[i][j] %= 2;
    }
  }
}
