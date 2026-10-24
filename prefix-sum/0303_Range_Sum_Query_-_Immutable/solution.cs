/*
303. Range Sum Query - Immutable

# 307. Range Sum Query - Mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
    You may assume that the array does not change.
    There are many calls to sumRange function.


*/

using System.Collections.Generic;

public class NumArray {
    private int[] nums;
    private Dictionary<int, int> dict = new Dictionary<int, int>();
    public NumArray(int[] nums) {
        this.nums = nums;
        int sum = 0;
        for(int i =0; i< nums.Length;i++){
            sum += nums[i];
            this.dict[i] = sum;
        }
    }

    public int SumRange(int i, int j) {
        if (i == 0)
            return this.dict[j];
        return this.dict[j] - this.dict[i-1];
    }
}
