/*
130. Surrounded Regions

https://leetcode.com/problems/surrounded-regions/
*/

/*
    1. DFS find all 'O' connect to the edge and mark them as '#'
    2. Loop through the board and mark all 'O' as 'X' and '#' as 'O'


    The DFS algorithm has a time complexity of O(V + E), where V is the number of vertices (cells) and E is the number of edges (connections between cells). 
    In this case, the number of vertices is at most rows * cols, and the number of edges is also at most rows * cols. 
    Therefore, the time complexity of each DFS call is O(rows * cols).
*/
function solve(board: string[][]): void {
  var rows = board.length;
  var cols = board[0].length;

  // Loop through the first column and last column(left and right border)
  // DFS to find all 'O' connect to border and mark them as '#'
  for (let row = 0; row < rows; row++) {
    if (board[row][0] == "O") {
      dfs(board, row, 0);
    }

    if (board[row][cols - 1] == "O") {
      dfs(board, row, cols - 1);
    }
  }
  // Loop through the first row and last row(top and bottom border)
  // DFS to find all 'O' connect to border and mark them as '#'

  for (let col = 0; col < cols; col++) {
    if (board[0][col] == "O") {
      dfs(board, 0, col);
    }
    if (board[rows - 1][col] == "O") {
      dfs(board, rows - 1, col);
    }
  }
  // Change a 'O' to 'X'
  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      if (board[row][col] == "O") {
        board[row][col] = "X";
      }
    }
  }
  // Change a '#' to 'O'
  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      if (board[row][col] == "#") {
        board[row][col] = "O";
      }
    }
  }
}
function dfs(board: string[][], row: number, col: number): void {
  board[row][col] = "#";

  if (row - 1 > 0 && board[row - 1][col] == "O") {
    dfs(board, row - 1, col);
  }

  if (row + 1 < board.length - 1 && board[row + 1][col] == "O") {
    dfs(board, row + 1, col);
  }
  if (col - 1 > 0 && board[row][col - 1] == "O") {
    dfs(board, row, col - 1);
  }

  if (col + 1 < board[0].length - 1 && board[row][col + 1] == "O") {
    dfs(board, row, col + 1);
  }
}
