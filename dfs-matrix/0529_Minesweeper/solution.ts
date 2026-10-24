/*
529. Minesweeper

https://leetcode.com/problems/minesweeper/
*/

/*
  Solution: DFS
    Time complexity: O(m*n)
    Space complexity: O(m* n)

  M: unrevealed mine
  E: unrevealed empty
  B: revealed empty, has no adjacent mines
  X: revealed mine
    
  M->X   E-> number or B 
*/
function updateBoard(board: string[][], click: number[]): string[][] {
  const rows = board.length;
  const cols = board[0].length;

  const dfs = (col: number, row: number): void => {
    if (board[row][col] !== "E") return;
    let c = 0;
    for (let tx = col - 1; tx <= col + 1; ++tx) {
      for (let ty = row - 1; ty <= row + 1; ++ty) {
        if (tx >= 0 && tx < cols && ty >= 0 && ty < rows) {
          c += board[ty][tx] === "M" ? 1 : 0;
        }
      }
    }

    if (c > 0) {
      board[row][col] = c.toString();
      return;
    }

    board[row][col] = "B";

    for (let tx = col - 1; tx <= col + 1; ++tx) {
      for (let ty = row - 1; ty <= row + 1; ++ty) {
        if (tx >= 0 && tx < cols && ty >= 0 && ty < rows) {
          dfs(tx, ty);
        }
      }
    }
  };

  const [row, col] = click;
  dfs(col, row);

  // unrevealed mine -> revealed mine
  if (board[row][col] === "M") {
    board[row][col] = "X";
  }

  return board;
}
