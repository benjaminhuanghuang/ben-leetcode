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
