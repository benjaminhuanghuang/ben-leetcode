# 33. Search in Rotated Sorted Array

<https://leetcode.com/problems/search-in-rotated-sorted-array/>

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Reference:
    Cracking the Coding Interview   Ch6 P32
    Cracking the Coding Interview   9.11-11.3 P256

## Explain

为什么 while (left <= right) 而不是 left < right？因为当 left === right 时，搜索区间仍然有一个元素需要检查。

所以每次循环需要：

1. 判断哪一半是 sorted
2. 判断 target 是否在有序的那一半。
3. 如果在，缩小搜索范围；否则搜索另一半。

Case 1：左半边有序: nums[left] <= nums[mid]
因为左边界到 mid 如果没有跨越 Rotation Point（旋转点），那么这一段就是升序的。

接下来判断 target 是否在左半边的范围内：
nums[left] <= target && target < nums[mid]

Case 2：右半边有序： nums[left] > nums[mid]

判断 target 是否在右半边：
nums[mid] < target && target <= nums[right]
