package cn.huang.leetcode;

/*
410. Split Array Largest Sum

Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty
continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

    1 ≤ n ≤ 1000
    1 ≤ m ≤ min(50, n)

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

 */
public class LC_0410_SplitArrayLargestSum {
    /*
    对数组的和进行binary-search。可以想到，数组和的最小值是最大元素的值，最大值是所有元素的和（注意溢出），对该区间进行bin-search，直到找到合适的结果。
     */
    public int splitArray(int[] nums, int m) {
        //取出最大值和最小值
        int max = 0;
        long sum = 0;
        for (int num : nums) {
            max = Math.max(num, max);
            sum += num;
        }
        if (m == 1)
            return (int) sum;
        //binary search
        long l = max;
        long r = sum;
        while (l <= r) {
            long mid = (l + r) / 2;
            //调用valid函数判断当前值是否满足条件
            if (valid(mid, nums, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (int) l;
    }

    public boolean valid(long target, int[] nums, int m) {
        int count = 1;
        long total = 0; //对数组进行分段求和，每当和大于target时，就重新求和，如果数组总数大于m，则说明target太小，需要增加，返回false
        for (int num : nums) {
            total += num;
            if (total > target) {
                total = num;
                count++;
                if (count > m) {
                    return false;
                }
            }
        }
        return true;
    }
    /*
    https://www.youtube.com/watch?v=_k-Jb4b7b_0
    DP
    Binary Search
    */
}
