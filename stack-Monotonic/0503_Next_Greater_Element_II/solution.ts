/*
503. Next Greater Element II

https://leetcode.com/problems/next-greater-element-ii/
*/

/*

Monotonic Stack + HashTable 
Smilar to leetcode_496_next-greater-elements-i.ts
*/
function nextGreaterElements(nums: number[]): number[] {
  const n = nums.length;
  const stack: number[] = [];
  const res: number[] = new Array(n).fill(-1);

  for (let i = 2 * n; i >= 0; i--) {
    // push num when it is smaller than stack top
    while (stack.length > 0 && nums[i % n] >= stack[stack.length - 1]) {
      stack.pop();
    }
    res[i % n] = stack.length > 0 ? stack[stack.length - 1] : -1;
    stack.push(nums[i % n]);
  }
  return res;
}
