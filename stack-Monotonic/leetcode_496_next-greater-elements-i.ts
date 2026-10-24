/*
496. Next Greater Elements I

https://leetcode.com/problems/next-greater-element-i/
*/

/*
Monotonic Stack + HashTable
*/
function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
  const stack: number[] = [];
  // key: num, value: next greater element
  const map: Map<number, number> = new Map();

  for (let i = nums2.length - 1; i >= 0; i--) {
    // push num when it is smaller than stack top
    while (stack.length > 0 && nums2[i] >= stack[stack.length - 1]) {
      stack.pop();
    }
    // key is num, value is next greater element
    map.set(nums2[i], stack.length > 0 ? stack[stack.length - 1] : -1);
    stack.push(nums2[i]);
  }
  const ans: number[] = [];
  for (let i = 0; i < nums1.length; i++) {
    ans.push(map.get(nums1[i])!);
  }
  return ans;
}
/*
   Stack + HashTable (same as v1)
 
   Using a stack to store the nums whose next greater isn’t found yet.
 
   栈stack维护nums的递减子集，记nums的当前元素为n，栈顶元素为top

   重复弹出栈顶，直到stack为空，或者top大于n为止

   将所有被弹出元素的next greater element置为n

   时间复杂度O(n + m) 其中n为nums1的长度，m为nums2的长度

   http://bookshadow.com/weblog/2017/02/05/leetcode-next-greater-element-i/

   https://zxi.mytechroad.com/blog/algorithms/array/leetcode-496-next-greater-element-i/
 */

function nextGreaterElement2(nums1: number[], nums2: number[]): number[] {
  const stack: number[] = [];
  const next: Map<number, number> = new Map();

  for (const num of nums2) {
    while (stack.length > 0 && num > stack[stack.length - 1]) {
      next.set(stack.pop()!, num);
    }
    stack.push(num);
  }

  const ans: number[] = [];
  for (const num of nums1) {
    ans.push(next.has(num) ? next.get(num)! : -1);
  }

  return ans;
}
