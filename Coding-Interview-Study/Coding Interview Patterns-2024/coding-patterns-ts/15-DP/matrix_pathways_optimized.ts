function matrixPathwaysOptimized(m: number, n: number): number {
  // Initialize the first row (base case) — all 1s
  let prevRow: number[] = new Array(n).fill(1);

  // Iterate over rows starting from the second
  for (let r = 1; r < m; r++) {
    // Initialize current row with all 1s
    const currRow: number[] = new Array(n).fill(1);

    for (let c = 1; c < n; c++) {
      // Number of paths = from top (prevRow[c]) + from left (currRow[c - 1])
      currRow[c] = prevRow[c] + currRow[c - 1];
    }

    // Move to the next row
    prevRow = currRow;
  }

  // The last element contains the total paths to bottom-right cell
  return prevRow[n - 1];
}
/*
Time complexity: The time complexity of matrix_pathways is O(m • n) because each cell in the
DP table is populated once.

Space complexity: The space complexity is O(n) due to the two rows used to store the current and previous row.
*/
