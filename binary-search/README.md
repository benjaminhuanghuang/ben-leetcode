# Binary search

- Sorted array
- O(LogN)
- Two rules:
  - Shrink the search space every iteration (or recursion), change the left, right
  - Cannot exclude potential answers during each shrinking, mid -1 or mid?

## interval vs Loop condition

| 区间定义 | right 初值 | while 条件 | right 更新    |
| -------- | ---------- | ---------- | ------------- |
| `[l, r]` | `n - 1`    | `l <= r`   | `r = mid - 1` |
| `[l, r)` | `n`        | `l < r`    | `r = mid`     |

左闭右开区间[left, right)的含义：
left：当前可能的答案， right：一定不包含答案

循环条件 while (left < right)， 结束时：left === right

## 查找某个确切值target

区间为Closed interval[left, right], 因为要检查最后一个元素，所以右边必须包含
循环条件为 left <= right

```js
function binarySearch(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    if (nums[mid] === target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}
```

## lower_bound / upper_bound

[1 2 2 2 4 5] 查找 target = 2, lower_bound is 1(第一个2), upper_bound is 4 (值为4的元素)

lower_bound(x) 第一个(最左边) >= target 的位置，一个“不会再更小”的界限

- Finds the leftmost position of x
- If x exists → points to the first occurrence
- If x does not exist → points to where it should be inserted

upper_bound(x) 第一个(最左边) > target 的位置， 一个“不会再更大”的界限

- Finds the position after the last occurrence of x
- If x exists → points just past the rightmost x
- If x does not exist → same as lower_bound

use Half open interval [left, right), 因为插入位置可能等于 nums.length，方便返回
循环条件 while (left < right)， 结束时：left === right， 这个位置就是答案（插入点）。

出现次数 = upper_bound - lower_bound

在整个过程中：
left：已经确认“不可能是答案”的最右边界
right：可能是答案的最左边界

当循环结束时： left === right
此时这个位置：左边的元素：全部 < target， 这个位置以及右边：全部 ≥ target

```js
function lowerBound(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] >= target) {    // check(n) 满足
        right = mid;
    } else {
        left = mid + 1;
    }
  }
  return left; // 返回插入位置
}

function upperBound(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length; // [left, right)

  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    /*
    upperBound 的定义 返回第一个满足 nums[i] > target 的位置
    所以要把数组分成两部分 <= target 和  > target
    等于 target 的元素必须被“排除”
    */
    if (arr[mid] > target) { // check(n) 满足
        right = mid;
    } else {
        left = mid + 1;
    }
  }

  return left; // first index where nums[i] > target
}
```

## 查找第一个大于等于目标的元素

use [left, right)

```ts
function binarySearch(arr, target) {
  let left = 0;
  let right = arr.length - 1;
  let first_true_index = -1;

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    if (feasible(mid)) {
      first_true_index = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return first_true_index;
}
```

## 查找第一个小于等于目标的元素 , 最小满足条件的值

```js
function binarySearchAnswer() {
  let left = 最小可能值;
  let right = 最大可能值 + 1; // 左闭右开 [left, right)

  while (left < right) {
    const mid = Math.floor((left + right) / 2);

    if (check(mid)) {
      // mid 可行，答案在 [left, mid]
      right = mid;
    } else {
      // mid 不可行，答案在 [mid + 1, right)
      left = mid + 1;
    }
  }

  return left;
}
```
