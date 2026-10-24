function nQueens(n: number): number {
  let res = 0;

  function dfs(
    r: number,
    diagonalsSet: Set<number>,
    antiDiagonalsSet: Set<number>,
    colsSet: Set<number>
  ): void {
    // Termination condition: If we have reached the end of the rows,
    // we've placed all 'n' queens.
    if (r === n) {
      res += 1;
      return;
    }

    for (let c = 0; c < n; c++) {
      const currDiagonal = r - c;
      const currAntiDiagonal = r + c;

      // If there are queens on the current column, diagonal or
      // anti-diagonal, skip this square.
      if (
        colsSet.has(c) ||
        diagonalsSet.has(currDiagonal) ||
        antiDiagonalsSet.has(currAntiDiagonal)
      ) {
        continue;
      }

      // Place the queen by marking the current column, diagonal, and
      // anti-diagonal as occupied.
      colsSet.add(c);
      diagonalsSet.add(currDiagonal);
      antiDiagonalsSet.add(currAntiDiagonal);

      // Recursively move to the next row to continue placing queens.
      dfs(r + 1, diagonalsSet, antiDiagonalsSet, colsSet);

      // Backtrack by removing the current column, diagonal, and
      // anti-diagonal from the hash sets.
      colsSet.delete(c);
      diagonalsSet.delete(currDiagonal);
      antiDiagonalsSet.delete(currAntiDiagonal);
    }
  }

  dfs(0, new Set<number>(), new Set<number>(), new Set<number>());
  return res;
}

/*
Time complexity: The time complexity of n_queens is O(n!). 
• For the first queen, there are n choices for its position.
• For the second queen, there are n - a choices for its position, where a denotes the number of
squares on the second row attacked by the first queen.
• The third queen has n - b choices, where b denotes the number of squares on the third row
attacked by the previous two queens, and b < a.
• This process continues for subsequent queens, resulting in a total of n · (n - a) • (n - b) . .... 1
choices. Even though th is doesn't exactly equate ton! (n · (n - 1) · (n - 2) · ... - 1). this trend
approximately results in a factorial growth of the search space.


Space complexity: O(n) because the maximum depth of the recursion tree is n. 
The hash sets also contribute to this space complexity because they each store up to n values.
*/
