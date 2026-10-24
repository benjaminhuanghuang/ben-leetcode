/*
Greedy + 2 Passes
*/
function candies(ratings: number[]): number {
  const n = ratings.length;
  if (n === 0) return 0;

  // Step 1: Initialize each child with 1 candy
  const candies: number[] = new Array(n).fill(1);

  // First pass: left to right
  for (let i = 1; i < n; i++) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  // Second pass: right to left
  for (let i = n - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i + 1]) {
      candies[i] = Math.max(candies[i], candies[i + 1] + 1);
    }
  }

  // Sum up all candies
  return candies.reduce((a, b) => a + b, 0);
}

/*
Time complexity: O(n) because we perform two passes over the
ratings array.

Space complexity: O(n) due to the space taken up by the candies array.
*/
