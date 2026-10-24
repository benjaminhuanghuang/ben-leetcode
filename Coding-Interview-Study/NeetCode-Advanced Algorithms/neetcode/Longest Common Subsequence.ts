/*
    Longest Common Subsequence
    
    Given two strings s1 and s2, find the length of the longest common subsequence between the two strings.
*/

/* Time: O(2^(n + m)), Space: O(n + m)
树的深度最多是 n + m（i1 最多走 n 步，i2 最多走 m 步）
树的每层最多分裂 2 次
*/
function dfs(s1: string, s2: string): number {
  return dfsHelper(s1, s2, 0, 0);
}

// i1, i2 分别是 s1, s2 的 index
function dfsHelper(s1: string, s2: string, i1: number, i2: number): number {
  if (i1 === s1.length || i2 === s2.length) {
    return 0;
  }

  if (s1[i1] === s2[i2]) {
    return 1 + dfsHelper(s1, s2, i1 + 1, i2 + 1);
  } else {
    return Math.max(
      dfsHelper(s1, s2, i1 + 1, i2),
      dfsHelper(s1, s2, i1, i2 + 1)
    );
  }
}

// Time: O(n * m), Space: O(n + m)
function memoization(s1: string, s2: string): number {
  const N = s1.length,
    M = s2.length;
  const cache: number[][] = Array.from({ length: N }, () =>
    new Array(M).fill(-1)
  );
  return memoHelper(s1, s2, 0, 0, cache);
}

function memoHelper(
  s1: string,
  s2: string,
  i1: number,
  i2: number,
  cache: number[][]
): number {
  if (i1 === s1.length || i2 === s2.length) {
    return 0;
  }
  if (cache[i1][i2] !== -1) {
    return cache[i1][i2];
  }

  if (s1[i1] === s2[i2]) {
    cache[i1][i2] = 1 + memoHelper(s1, s2, i1 + 1, i2 + 1, cache);
  } else {
    cache[i1][i2] = Math.max(
      memoHelper(s1, s2, i1 + 1, i2, cache),
      memoHelper(s1, s2, i1, i2 + 1, cache)
    );
  }

  return cache[i1][i2];
}

// Time: O(n * m), Space: O(n + m)
function dp(s1: string, s2: string): number {
  const N = s1.length,
    M = s2.length;
  const dp: number[][] = Array.from({ length: N + 1 }, () =>
    new Array(M + 1).fill(0)
  );

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (s1[i] === s2[j]) {
        dp[i + 1][j + 1] = 1 + dp[i][j];
      } else {
        dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }

  return dp[N][M];
}

export {};
