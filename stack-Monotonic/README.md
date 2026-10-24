# Monotonic Stack

Key words:
the minimum index such that j > i and prices[j] <= prices[i]

For each element, find the first smaller/bigger element

“右边第一个更小/更大”
“下一个满足条件的元素”

## Template

```txt
while stack 非空 且 当前值比栈顶更满足条件:
    栈顶出栈并记录答案
当前索引入栈
```

找右侧第一个更大的元素

```ts
function nextGreaterElement(nums: number[]): number[] {
  const n = nums.length;
  const ans = Array(n).fill(-1);
  const stack: number[] = []; // 存索引

  for (let i = 0; i < n; i++) {
    while (stack.length > 0 && nums[i] > nums[stack[stack.length - 1]]) {
      const idx = stack.pop()!;
      ans[idx] = nums[i];
    }
    stack.push(i);
  }

  return ans;
}
```

```ts
for (let i = 0; i < nums.length; i++) {
  // step 1, descending stack, push num when idt is < stack top
  while (!stack.isEmpty && nums[i] >= stack.peek()) {
    stack.pop();
  }
  // step 2
  res.push(stack.isEmpty ? -1 : stack.peek());

  // step 3
  stack.push(nums[i]);
}

function monoStack(insertEntries) {
  const stack = [];

  for (let entry of insertEntries) {
    // Compare current element with the stop top
    while (stack.length > 0 && stack[stack.length - 1] <= entry) {
      stack.pop();
      // Do something with the popped item here
    }
    stack.push(entry);
  }
}
```

## Leetcode list

1. Next Greater Element I
2. Next Greater Element I|
3. Next Greater Node In Linked List
4. Daily Temperatures
5. Remove Duplicate Letters
6. Smallest Subsequence of Distinct Characters
7. Remove K Digits
8. Trapping Rain Water
9. Largest Rectangle in Histogram

## Reference

<https://www.youtube.com/watch?v=7QEIZy1pp2o>
