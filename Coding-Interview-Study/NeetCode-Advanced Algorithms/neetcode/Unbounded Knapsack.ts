/*
Unbounded Knapsack

Q: Given a list of N items, and a backpack with a limited capacity, return the maximum total profit 
that can be contained in the backpack. The i-th item's profit is profit[i] and it's weight is weight[i]. 
Assume you can have an unlimited number of each item available.

*/

// Brute Force Solution
// Time: O(2^c), Space: O(c)
// Where c is the capacity
function dfs(profit: number[], weight: number[], capacity: number): number {
  return dfsHelper(0, profit, weight, capacity);
}

function dfsHelper(
  i: number,
  profit: number[],
  weight: number[],
  capacity: number
): number {
  if (i === profit.length) {
    return 0;
  }

  // Skip item i
  let maxProfit = dfsHelper(i + 1, profit, weight, capacity);

  // Include item i
  const newCap = capacity - weight[i];
  if (newCap >= 0) {
    // 选了第 i 个物品之后：不跳到下一个 仍然可以继续选第 i 个物品
    const p = profit[i] + dfsHelper(i, profit, weight, newCap);
    // Compute the max
    maxProfit = Math.max(maxProfit, p);
  }

  return maxProfit;
}

// Memoization Solution
// Time: O(n * m), Space: O(n * m)
// Where n is the number of items & m is the capacity
function memoization(
  profit: number[],
  weight: number[],
  capacity: number
): number {
  const N = profit.length,
    M = capacity;
  // A 2D array, with N rows and M+1 columns, init with -1's
  const cache: number[][] = Array.from({ length: N }, () =>
    new Array(M + 1).fill(-1)
  );
  return memoHelper(0, profit, weight, capacity, cache);
}

function memoHelper(
  i: number,
  profit: number[],
  weight: number[],
  capacity: number,
  cache: number[][]
): number {
  if (i === profit.length) {
    return 0;
  }
  if (cache[i][capacity] !== -1) {
    return cache[i][capacity];
  }

  // Skip item i
  cache[i][capacity] = memoHelper(i + 1, profit, weight, capacity, cache);

  // Include item i
  const newCap = capacity - weight[i];
  if (newCap >= 0) {
    const p = profit[i] + memoHelper(i, profit, weight, newCap, cache);
    // Compute the max
    cache[i][capacity] = Math.max(cache[i][capacity], p);
  }

  return cache[i][capacity];
}

// Dynamic Programming Solution
// Time: O(n * m), Space: O(n * m)
// Where n is the number of items & m is the capacity
function dp(profit: number[], weight: number[], capacity: number): number {
  const N = profit.length,
    M = capacity;
  const dp: number[][] = Array.from({ length: N }, () =>
    new Array(M + 1).fill(0)
  );

  // Fill the first column and row to reduce edge cases
  for (let i = 0; i < N; i++) {
    dp[i][0] = 0;
  }
  for (let c = 0; c <= M; c++) {
    if (weight[0] <= c) {
      dp[0][c] = profit[0];
    }
  }

  for (let i = 1; i < N; i++) {
    for (let c = 1; c <= M; c++) {
      const skip = dp[i - 1][c];
      let include = 0;
      if (c - weight[i] >= 0) {
        include = profit[i] + dp[i][c - weight[i]];
      }
      dp[i][c] = Math.max(include, skip);
    }
  }

  return dp[N - 1][M];
}

export {};
