/*


*/

function nextLargestNumberToTheRight(nums: number[]): number[] {
  const res = new Array(nums.length).fill(0);
  // Monotonic Stack， 栈内元素从栈底到栈顶递减， 保证栈顶总是候选的“下一个更大元素”
  const stack: number[] = [];

  // Traverse from right to left
  for (let i = nums.length - 1; i >= 0; i--) {
    // Pop smaller or equal elements
    while (stack.length > 0 && stack[stack.length - 1] <= nums[i]) {
      stack.pop();
    }

    // If stack not empty, top is the next greater element; else -1
    res[i] = stack.length > 0 ? stack[stack.length - 1] : -1;

    // Push current element
    stack.push(nums[i]);
  }

  return res;
}
/*
Time complexity: The time complexity of next_largest_number_to_the_right is O(n). This is
because each value of nums is pushed and popped from the stack at most once.

Space complexity: The space complexity is O(n) because the stack can potentially store all n values.
*/
