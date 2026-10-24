/*
 120. Triangle
 https://leetcode.com/problems/triangle/description/
*/

/*
DFS
Time complexity:
1. DFS Traversal without Memoization: each call would branch into two recursive calls, time ccomplexity is O(2^N)
2. Memoization: each subproblem is solved only once. In this problem, there are N^2 unique subproblems to solve.
3. Work Down per subprolem, aach subproblem involves a constant amount of work (checking memoization and calculating the minimum path sum). 
   Thus, the time complexity per subproblem is O(1)

Space Complexity:
    The space complexity is also O(N^2) due to the storage required for the memoization table, 
    which stores a value for each of the  O(N^2) subproblems.
*/
function minimumTotal(triangle: number[][]): number {
  const memo: number[][] = [];
  const n = triangle.length;

  // Initialize memoization array with -1
  for (let i = 0; i < n; i++) {
    memo.push(new Array(n).fill(-1));
  }

  function dfs(row: number, col: number): number {
    // Base case: if it's the last row, return the value at triangle[row][col]
    if (row === n - 1) {
      return triangle[row][col];
    }

    // If the value is already computed, return it
    if (memo[row][col] !== -1) {
      return memo[row][col];
    }

    // Recursively calculate the minimum path sum for the current position
    const leftPath = dfs(row + 1, col);
    const rightPath = dfs(row + 1, col + 1);

    // Take the minimum of the two possible paths and add the current value
    const minPathSum = Math.min(leftPath, rightPath) + triangle[row][col];

    // Memoize the result
    memo[row][col] = minPathSum;

    return minPathSum;
  }

  // Start the DFS from the top of the triangle (0, 0)
  return dfs(0, 0);
}

/*
DP
https://www.youtube.com/watch?v=OM1MTokvxs4

Time Complexity is O(N^2), where n is the number of rows in the triangle. 
This is because we have a nested loop where the outer loop runs n times and the inner loop 
runs up to n times.

Space Complexity is O(N), because we use a single array dp of size n to store the minimum path sums. 
*/
function minimumTotal_DP(triangle: number[][]): number {
  const n = triangle.length;

  // Create a DP array that starts as a copy of the last row of the triangle
  const dp = triangle[n - 1].slice();

  // Start from the second last row and move upwards
  for (let row = n - 2; row >= 0; row--) {
    for (let col = 0; col <= row; col++) {
      // Update the DP array with the minimum path sum for each position
      dp[col] = triangle[row][col] + Math.min(dp[col], dp[col + 1]);
    }
  }

  // The top element of the DP array will contain the minimum path sum
  return dp[0];
}

export { minimumTotal, minimumTotal_DP };
