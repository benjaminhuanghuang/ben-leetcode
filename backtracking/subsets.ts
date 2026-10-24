/*

Subsets


Talk-through: Backtracking where every path, not just leaves, is a valid
subset — record it on entry to each call. Start the inner loop at the
current index (not 0) to only move forward, which avoids generating the same
subset in a different order.

Time complexity: big O of n * 2^n, 
Space complexity: big O of n for the recursion stack.
*/
function subsets(nums: number[]): number[][] {
  const result: number[][] = [];
  const path: number[] = [];

  function backtrack(start: number): void {
    result.push([...path]);

    for (let i = start; i < nums.length; i++) {
      path.push(nums[i]);
      backtrack(i + 1);
      path.pop();
    }
  }

  backtrack(0);

  return result;
}
