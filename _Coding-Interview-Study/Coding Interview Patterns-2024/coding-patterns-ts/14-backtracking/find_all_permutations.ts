function find_all_permutations(nums: number[]): number[][] {
  const res: number[][] = [];

  backtrack(nums, [], new Set<number>(), res);

  return res;
}

function backtrack(
  nums: number[],
  candidate: number[],
  used: Set<number>,
  res: number[][]
): void {
  // If the current candidate is a complete permutation, add it to the result.
  if (candidate.length === nums.length) {
    res.push([...candidate]);
    return;
  }

  for (const num of nums) {
    if (!used.has(num)) {
      // Add 'num' to the current permutation and mark it as used.
      candidate.push(num);
      used.add(num);

      // Recursively explore all branches using the updated
      // permutation candidate.
      backtrack(nums, candidate, used, res);

      // Backtrack by reversing the changes made.
      candidate.pop();
      used.delete(num);
    }
  }
}

export {};
/*
Time complexity: The time complexity of find_all_permutations is O(n x n!). 
• Starting from the root, we recursively explore n candidates.
• For each of these n candidates, we explore n-1 more candidates, then n- 2 more candidates,
etc, until we have explored all permutations. This results in a total of nx(n- l)x(n-2)... x 1 = n!
permutations.
• For each of the n! permutations, we make a copy of it and add it to the output, which takes
O(n) time.
This results in a total time complexity of O(n!) x O(n) = O(n x n!) .

Space complexity: The space complexity is O(n) because the maximum depth of the recursion tree
is n. The algorithm also maintains the candidate and used data structures, both of which also
contribute O(n) space. The res array does not contribute to space complexity.

*/
