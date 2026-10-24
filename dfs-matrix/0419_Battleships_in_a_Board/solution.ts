/*
419. Battleships in a Board

https://leetcode.com/problems/battleships-in-a-board/
*/

/*
    https://www.youtube.com/watch?v=q7kHTti3910
*/
function countBattleships(board: string[][]): number {
  let count = 0;

  for (let row = 0; row < board.length; ++row) {
    for (let col = 0; col < board[row].length; ++col) {
      if (board[row][col] === "X") {
        if (row > 0 && board[row][col] === board[row - 1][col]) {
          // this x belongs to the same ship
          continue;
        }
        if (col > 0 && board[row][col] === board[row][col - 1]) {
          // this x belongs to the same ship
          continue;
        }
        ++count;
      }
    }
  }

  return count;
}
