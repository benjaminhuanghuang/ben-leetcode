/*
228. Summary Ranges
https://leetcode.com/problems/summary-ranges/
*/

function summaryRanges(nums: number[]): string[] {
  const result: string[] = [];
  let start = 0;
  let end = 0;
  while (end < nums.length) {
    while (end + 1 < nums.length && nums[end] + 1 === nums[end + 1]) {
      end++;
    }
    if (start === end) {
      result.push(`${nums[start]}`);
    } else {
      result.push(`${nums[start]}->${nums[end]}`);
    }
    end++;
    start = end;
  }
  return result;
}
