package cn.huang.leetcode;

/*
	88	 Merge Sorted Array
	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
    Example:

    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    Output: [1,2,2,3,5,6]
 */
public class LC_0088_MergeSortedArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        int i = m + n - 1;

        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] >= nums2[i2]) {
                nums1[i--] = nums1[i1--];
            } else {
                nums1[i--] = nums2[i2--];
            }
        }

        if(i1 == -1) {
            while (i2 >= 0) {
                nums1[i--] = nums2[i2--];
            }
        }
    }
}
