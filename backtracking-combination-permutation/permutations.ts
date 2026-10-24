/*

Permutations


Talk-through: Backtracking — build the permutation one slot at a time. Track
which numbers are already used; at each step, try every unused number, push
it, recurse, then pop it (undo) before trying the next option. A full
permutation is recorded once the running path reaches the input's length.

Time big O of n * n!, space big O of n for the recursion stack.
*/
function permute(nums: number[]): number[][] {
  const result: number[][] = [];
  const path: number[] = [];
  const used = new Array(nums.length).fill(false);

  function backtrack(): void {
    if (path.length === nums.length) {
      result.push([...path]);
      return;
    }

    for (let i = 0; i < nums.length; i++) {
      if (used[i]) continue;

      // choose
      used[i] = true;
      path.push(nums[i]);

      // explore
      backtrack();

      // undo
      path.pop();
      used[i] = false;
    }
  }

  backtrack();
  return result;
}
