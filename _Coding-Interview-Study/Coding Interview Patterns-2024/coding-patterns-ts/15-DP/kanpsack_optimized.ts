function knapsackOptimized(
  cap: number,
  weights: number[],
  values: number[]
): number {
  const n = values.length;

  // Initialize previous row (DP values of the row below)
  let prevRow: number[] = new Array(cap + 1).fill(0);

  // Fill the table bottom-up
  for (let i = n - 1; i >= 0; i--) {
    const currRow: number[] = new Array(cap + 1).fill(0);

    for (let c = 1; c <= cap; c++) {
      if (weights[i] <= c) {
        // Max of including or excluding the current item
        currRow[c] = Math.max(values[i] + prevRow[c - weights[i]], prevRow[c]);
      } else {
        // Item doesn't fit → exclude it
        currRow[c] = prevRow[c];
      }
    }

    // Update prevRow for the next iteration
    prevRow = currRow;
  }

  return prevRow[cap];
}
/*
Time complexity: The time complexity of knapsack is O(n . cap) because each cell of the DP table
is populated once.
Space complexity: The space complexity is O(cap) 
*/
