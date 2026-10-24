/*
Subsets
Q: Given a list of distinct numbers that are not necessarily distinct, return all distinct subsets
// Time: O(n * 2^n), Space: O(n)
*/

function subsetsWithDuplicates(nums: number[]): number[][] {
  nums.sort((a, b) => a - b);
  const subsets: number[][] = [];
  const curSet: number[] = [];

  helper2(0, nums, curSet, subsets);
  return subsets;
}

function helper2(
  i: number,
  nums: number[],
  curSet: number[],
  subsets: number[][]
): void {
  if (i >= nums.length) {
    subsets.push([...curSet]);
    return;
  }

  // decision to include nums[i]
  curSet.push(nums[i]);
  helper2(i + 1, nums, curSet, subsets);
  curSet.pop();

  // decision NOT to include nums[i]
  while (i + 1 < nums.length && nums[i] === nums[i + 1]) {
    i++;
  }
  helper2(i + 1, nums, curSet, subsets);
}
