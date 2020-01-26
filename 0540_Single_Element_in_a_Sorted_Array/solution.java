package cn.huang.leetcode;

/*
540. Single Element in a Sorted Array
Given a sorted array consisting of only integers where every element appears twice except for one element which
appears once. Find this single element that appears only once.

Note: Your solution should run in O(log n) time and O(1) space.
 */
public class LC_0540_SingleElementinaSortedArray {
    public int singleNonDuplicate_N(int[] nums) {
        int L = nums.length;
        int ans = 0;
        for (int i = 0; i < L; i++) {
            ans ^= nums[i];
        }
        return ans;
    }

    //  Solution 2  O(n)
    // 这个数只能在index 为偶数的位置，
    // Compare nums[i] and nums[i + 1] if not equal return nums[i] , i +=2


    /*


    初始令左、右指针lo, hi分别指向0, len(nums) - 1

    当lo < hi时执行循环：

    令mi = (lo + hi) / 2

    若nums[mi] == nums[mi - 1]：

    数组可以分为[lo, mi - 2], [mi + 1, hi]两部分，目标元素位于长度为奇数的子数组中。

    同理，若nums[mi] == nums[mi + 1]：

    数组可以分为[lo, mi - 1], [mi + 2, hi]两部分，目标元素位于长度为奇数的子数组中。

    若nums[mi]与nums[mi - 1], nums[mi + 1]均不相等，则返回nums[mi]
     */
    public int singleNonDuplicate(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            // m, n 是一个数对
            // int n = m % 2 == 0 ? m + 1 : m - 1;
            int n = m ^ 1;    // 根据 m是偶数还是奇数 把最后一位反转
            if (nums[m] == nums[n])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
}
