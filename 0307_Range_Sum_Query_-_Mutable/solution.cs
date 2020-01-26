/*
307. Range Sum Query - Mutable

# 303. Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

*/
//http://www.cnblogs.com/grandyang/p/4985506.html
// http://blog.csdn.net/xyt8023y/article/details/49946789

using System.Collections.Generic;

public class NumArrayMutalbe {
    private int[] num;
    private int[] bit;


    public NumArrayMutalbe(int[] nums) {
        this.num = new int[nums.Length + 1];
        this.bit = new int[nums.Length + 1];

        for (int i = 0; i < nums.Length; ++i) {
            Update(i, nums[i]);
        }
    }

    public void Update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i +1; j< num.Length; j+=(j&-j))
        {
            bit[i] += diff;
        }
        num[i+1] = val;
    }

    public int SumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }

    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) 
        {
            res += bit[j];
        }
        return res;
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.SumRange(0, 1);
// numArray.Update(1, 10);
// numArray.SumRange(1, 2);