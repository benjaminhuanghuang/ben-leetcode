/*
3159. Find Occurrences of an Element in an Array

https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/
*/

function occurrencesOfElement(
  nums: number[],
  queries: number[],
  x: number
): number[] {
  const ids = nums.map((v, i) => (v === x ? i : -1)).filter((v) => v !== -1);
  return queries.map((i) => ids[i - 1] ?? -1);
}
