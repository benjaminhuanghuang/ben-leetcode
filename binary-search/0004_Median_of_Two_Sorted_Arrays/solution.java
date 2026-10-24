package cn.huang.leetcode;
/*

4. Median of Two Sorted Arrays


 */
public class LC_0004_MedianofTwoSortedArrays {
    /*
        https://www.youtube.com/watch?v=Be-u2dLh8Aw
        https://www.youtube.com/watch?v=oVPIQdHt_T8
        Case1: m + n is even, median = (number[total/2] + number[total/2 +1]) /2
        Case2: m + n is odd, median =  number[total/2 +1]


        对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1], 若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2;

        设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素;
        取A[k / 2] B[k / 2] 比较; 如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法);
        反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的; k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决;
        如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
    */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length, left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }


    int findKth(int[] nums1, int i, int[] nums2, int j, int k) {
        // Case 1: overstep
        if (i >= nums1.length)
            return nums2[j + k - 1];    // all of nums in nums1 were removed
        if (j >= nums2.length)
            return nums1[i + k - 1];
        // case 2: k =1
        if (k == 1) return Math.min(nums1[i], nums2[j]);

        // case 3: 每次砍掉 k／2个数字
        int midVal1 = (i + k / 2 - 1 < nums1.length) ? nums1[i + k / 2 - 1] : Integer.MAX_VALUE;
        int midVal2 = (j + k / 2 - 1 < nums2.length) ? nums2[j + k / 2 - 1] : Integer.MAX_VALUE;
        // cut number for nums1 or nums2
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
}
