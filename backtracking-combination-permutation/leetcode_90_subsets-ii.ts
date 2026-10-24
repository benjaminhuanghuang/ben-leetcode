/*
90. Subsets II

https://leetcode.com/problems/subsets-ii/

78. Subsets
*/

/*
The difference between this problem and leetcode_78_subsets.ts is that this problem has 
duplicates in the input array.

To avoid duplicates, 
- sort the input array first, 
- skip the duplicates
*/
function subsetsWithDup(nums: number[]): number[][] {
  nums.sort((a, b) => a - b); // skip the duplicates
  const ans: number[][] = [];
  const cur: number[] = [];

  for (let i = 0; i <= nums.length; i++) {
    backtrack(nums, i, 0, cur, ans); // i: length of the subset
  }

  return ans;
}

function backtrack(
  nums: number[],
  n: number,
  startPos: number,
  cur: number[],
  ans: number[][]
): void {
  if (n == cur.length) {
    ans.push([...cur]); // push a copy of cur to ans!
    return;
  }

  for (let i = startPos; i < nums.length; i++) {
    if (i != startPos && nums[i] == nums[i - 1]) {
      // skip the duplicates
      continue;
    }
    cur.push(nums[i]);
    backtrack(nums, n, i + 1, cur, ans);
    cur.pop();
  }
}
