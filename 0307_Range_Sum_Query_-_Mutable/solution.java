package cn.huang.leetcode;
/*
307. Range Sum Query - Mutable

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

/*
https://www.programcreek.com/2014/04/leetcode-range-sum-query-mutable-java/
http://www.cnblogs.com/grandyang/p/4985506.html
 */
public class LC_0307_RangeSumQuery_Mutable {

    class NumArray {

        int[] btree;   // Binary Index tree
        int[] arr;

        public NumArray(int[] nums) {
            btree = new int[nums.length + 1];
            arr = nums;

            for (int i = 0; i < nums.length; i++) {
                add(i + 1, nums[i]);
            }
        }

        void add(int i, int val) {
            //最低位的计算方法有两种，一种是x&(x^(x–1))，另一种是利用补码特性x&-x。
            for (int j = i; j < btree.length; j = j + (j & (-j))) {
                btree[j] += val;
            }
        }

        void update(int i, int val) {
            add(i + 1, val - arr[i]);
            arr[i] = val;
        }

        public int sumRange(int i, int j) {
            return sumHelper(j + 1) - sumHelper(i);
        }

        public int sumHelper(int i) {
            int sum = 0;
            for (int j = i; j >= 1; j = j - (j & (-j))) {
                sum += btree[j];
            }
            return sum;
        }
    }
}
