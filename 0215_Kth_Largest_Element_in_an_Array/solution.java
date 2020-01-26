package cn.huang.leetcode;

/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element
in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */
public class LC_0215_KthLargestElementinanArray {
    /*
    https://www.youtube.com/watch?v=ow04KXJ0kG4
    Quick sort
    Time:
     */
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0)
            return 0;

        int left = 0;
        int right = nums.length - 1;

        while (true) {
            int pos = partition(nums, left, right);
            if (pos + 1 == k) {
                return nums[pos];
            } else if (pos + 1 > k) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }

    /*

     */
    private int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        // 大于pivot的放左边，小于pivot的放右边
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums, l++, r--);
            }
            if(nums[l] >= pivot)
                l++;
            if(nums[r] <= pivot)
                r--;
        }
        swap(nums, left, r);  // 把pivot放到中间
        return r;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
