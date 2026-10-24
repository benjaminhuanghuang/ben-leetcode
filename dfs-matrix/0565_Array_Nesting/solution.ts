/*
565. Array Nesting

https://leetcode.com/problems/array-nesting/

- 442. Find All Duplicates in an Array
*/

/*
    Approach: DFS
*/
function arrayNesting(nums: number[]): number {
  const len = nums.length;
  if (len === 1) {
    return 1;
  }

  // Or mark the visited element as -1
  const visited: boolean[] = new Array(len).fill(false);

  let res = 0;

  for (let i = 0; i < len; i++) {
    let k = i;
    let count = 0;
    while (!visited[k]) {
      count++;
      visited[k] = true;
      k = nums[k];
    }
    res = Math.max(res, count);
  }
  return res;
}
