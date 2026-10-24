function longestCommonSubsequenceOptimized(s1: string, s2: string): number {
  const n = s2.length;
  let prevRow: number[] = new Array(n + 1).fill(0);

  // Iterate from the last row upwards
  for (let i = s1.length - 1; i >= 0; i--) {
    const currRow: number[] = new Array(n + 1).fill(0);

    for (let j = n - 1; j >= 0; j--) {
      if (s1[i] === s2[j]) {
        // Characters match → 1 + diagonal
        currRow[j] = 1 + prevRow[j + 1];
      } else {
        // Characters don't match → max of skipping one character
        currRow[j] = Math.max(prevRow[j], currRow[j + 1]);
      }
    }

    // Update previous row
    prevRow = currRow;
  }

  return prevRow[0];
}
/*
space complexity to O(n) .
*/
