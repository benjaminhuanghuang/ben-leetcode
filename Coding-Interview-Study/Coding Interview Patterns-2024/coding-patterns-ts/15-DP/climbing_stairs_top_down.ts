function climbingStairsTopDown(
  n: number,
  memo: Record<number, number> = {}
): number {
  // Base cases
  if (n <= 2) {
    return n;
  }

  // If result already computed, return it
  if (memo[n]) {
    return memo[n];
  }

  // Recursive relation:
  // ways(n) = ways(n - 1) + ways(n - 2)
  memo[n] =
    climbingStairsTopDown(n - 1, memo) + climbingStairsTopDown(n - 2, memo);

  return memo[n];
}

/*
Time complexity:
, Without memoization, the time complexity of climbing_stairs_top_down is O(2^n) because
the depth of the recursion tree is n, and its branching factor is 2 since we make 2 recursive
calls at each point in the tree.
, With memoization, we ensure each subproblem is solved only once. Since there are n possible
subproblems (one for each step from step 1 to step n), the time complexity is O(n).

Space complexity: The space complexity is O(n) due to the recursive call stack, which grows to a
height of n. The memoization array also contributes to the space occupied by storing n key-value
pairs.
*/
