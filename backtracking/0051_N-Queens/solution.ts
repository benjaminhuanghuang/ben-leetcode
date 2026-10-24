/*
51. N-Queens
https://leetcode.com/problems/n-queens/

*/

/*
    https://www.youtube.com/watch?v=Xa-yETqFNEQ

    Hint: each row has one queen, each column has one queen, each diagonal has one queen
        Only need to check row, row + 1.....
    describe the diagonal: There are 
        2N-1 diaonla line (right top to left bottom) the index is x + y
        and 2N-1 diagonal line (left top to right bottom) the index is x - y + n - 1

    The sudo code:

    available(x,y):
        return !col[x] && !diag1(x+y) && !diag2(x,y) 

    # y is the row number  
    # n is the total number of rows  
    # b is the current board, may be a answer
    n_queens(y, n, b, ans):
        if(y == n):  //exceed the last row
            ans.add(b)
            return
        for x in range(n):
            if not attacked(x, y): continue
            
            put_queen(x, y, b)
            n_queens(y+1, n, b, ans)
            remove_queen(x, y, b)

*/
function solveNQueens(n: number): string[][] {
  const ans: string[][] = [];

  function dfs(n: number, row: number, cur: number[]) {
    if (row === n) {
      // exceed the last row, find a answer
      ans.push(generateBoard(cur, n));
      return;
    }

    for (let col = 0; col < n; col++) {
      if (isValid(cur, row, col, n)) {
        cur.push(col);
        dfs(n, row + 1, cur);
        cur.pop();
      }
    }
  }

  function generateBoard(answer: number[], n: number): string[] {
    return answer.map((col) => ".".repeat(col) + "Q" + ".".repeat(n - col - 1));
  }

  function isValid(
    board: number[],
    row: number,
    col: number,
    n: number
  ): boolean {
    for (let i = 0; i < row; i++) {
      // check the queens in the previous rows
      if (board[i] === col) return false;
      // the angle is 45 degree
      if (Math.abs(board[i] - col) === Math.abs(i - row)) return false;
    }
    return true;
  }

  // [] is the current board, [row] is the col of the queen
  dfs(n, 0, []); // start from row 0 with empty board
  return ans;
}
