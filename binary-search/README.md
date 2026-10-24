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

---

## (merged from _CodingTemplates/Binary Search Recursive iterative.md)

# Binary Search recursive version and iterative version

```js
// recursive version
// Time complexity: O(log n), 每次搜索范围减半,所以时间复杂度是 O(log n)
// Space complexity: O(log n),因为递归调用栈会有 log n 层。
// 更贴近"分治"的定义, 数组极大时理论上有栈溢出可能
function binarySearch(arr, l, r, x) {
    if (r >= l) {
        const mid = l + Math.floor((r - l) / 2);
        if (arr[mid] === x) return mid;
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
```

```js
// iterative version
// Time complexity: O(log n), 每次搜索范围减半,所以时间复杂度是 O(log n)
// Space complexity: O(1)
function binarySearch(arr, x) {
    let l = 0, r = arr.length - 1;
    while (l <= r) {
        const m = l + Math.floor((r - l) / 2);
        if (arr[m] === x) return m;
        
        if (arr[m] < x) 
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
```

---

## (merged from _CodingTemplates/BinarySearch-Huahua.md)

# HuaHua Template

<https://www.youtube.com/watch?v=v57lNF2mb_s>

find the smallest value to satisfy g()

```ts

```

## Find 唯一确定解 (注意不是有唯一最优解: [left, right]

- 1. Valid Perfect Square
- 1. The K Weakest Rows in a Matrix (find last position of 1)

```ts
while (left<=right)
{
  mid = ...;
  if (isOK(mid))
    return mid;
  else if (isTooLarge(mid))
    mid = right-1;
  else if (isTooSmall(mid))
    mid = left+1;
}
return -1;
```

## Find Smallest element Greater Than Target: [left, right)

- 1. Find Smallest Letter Greater Than Target
- 1. Search Insert Position

## Find biggest number <= target: [left, right]

1. Arranging Coins

1. Find a value
   Time complexity: O(1og (r-1) *[f(m) + g(m)])
   Space complexity: O(1)

```
// Search range: [l, r)
def binary_search(l, r):
    while l < r:
        m = 1 + (r - l) // 2
        if f(m): return m # optional, is element[m] is the target
        if g(m):   # determain the new search range
            r = m     # new range [l, m)
        else
            l = m + 1 # new range [m+l, r)
    return l # or not found, l is the smallest value can make g(m) is true
```

1. The elements in the array are NOT uniqe, find lower_bound or upper_bound

lower_bound (x): first index of i, such that A[i] >= x
upper_bound(x): first index of i, such that A[i] > x

A = [1, 2, 2, 2, 4, 4, 5]
lower_bound (A, 2) = 1, lower_bound(A, 3) = 4 (first value>=3 is A[4], 3 does not exist)
upper_bound(A, 2) = 4, upper_bound(A, 5) = 7 (does not exist)

upper_bound - lower_bound => elements count

```py
def lower_bound(A, val, l, r):
    while l < r:
        m = l + (r - l) / 2
        if A[m] >= val: # g(m)  // find minimin m can make g(m) is true
            r = m
        else
            l = m + 1
    return l // Find the smallest index to satisfy g(index)

def upper bound (A, val, l, r):
    while l < r:
        m = l + (r - l) / 2
        if A[m] > val: # g(m)  // find minimin m can make g(m) is true
            r = m
        else
            l = m + 1
    return l   // Find the smallest index to satisfy g(index)
```

## TuringPlate Template

<https://www.youtube.com/watch?v=j2_JW3In9PE&list=PLV5qT67glKSErHD66rKTfqerMYz9OaTOs&index=3>

Template 1: Search a value:

```js
while (l <= r) l = mid + 1;
r = mid - 1;
```

Template 2: Find a value with condition, like a number bigger than 4

```js
while (l < r) l = mid;
r = mid - 1;
or;
l = mid + 1;
r = mid;
```

Find the first occurrence of 2 in array [1,1,2,2,2,6,7]

Find the last occurrence of 2 in array [1,1,2,2,2,6,7]

Template 3: general

```js
while (l < r - 1) ((l = mid), (r = mid));
```

---

## (merged from _CodingTemplates/BinarySearch.md)

# Binary Search

- 找值(target 在不在、下标几)用`[l, r]`，
- 找边界(第一个 ≥ target、插入位置)用`[l, r)`

## Template

```js
function binarySearch(nums, target) {
  let left = 0;
  let right = nums.length - 1;

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    if (nums[mid] === target) return mid;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
```

### `[l,r)`

```js
// 第一个 >= target 的下标
function lowerBound(nums, target) {
  let left = 0, right = nums.length; // 右开！
  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);
    if (nums[mid] < target) left = mid + 1;
    else right = mid; // mid 可能是答案，保留
  }
  return left;
}

// 第一个 > target 的下标
function upperBound(nums, target) {
  let left = 0, right = nums.length;
  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);
    if (nums[mid] <= target) left = mid + 1;
    else right = mid;
  }
  return left;
}

```

### Find first YES

<https://www.youtube.com/watch?v=25086D5uZmY>

迭代的不变式：区间包含第一个x 并且p(x)是true

```js
// [lo, hi)
function binarySearch(lo, hi, p) {
  while (lo < hi) {
    const mid = lo + Math.floor((hi - lo) / 2);
    if (p(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  if (!p(lo)) {
    throw new Error("p(x) is false for all x in S!");
  }

  return lo; // lo is the least x for which p(x) is true
}
```

## Complexity

Time: O(log n) — 每步砍掉一半
Space: O(1) — 迭代版就几个变量

## Sample
