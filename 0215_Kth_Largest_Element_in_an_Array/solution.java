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
    public int findKthLargest_pq(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(k);
        for (int i : nums) {
            q.offer(i);

            if (q.size() > k) {
                q.poll();
            }
        }

        return q.peek();
    }

    /*
     * https://www.youtube.com/watch?v=ow04KXJ0kG4 Quick sort Time:
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
            if (nums[l] >= pivot)
                l++;
            if (nums[r] <= pivot)
                r--;
        }
        swap(nums, left, r); // 把pivot放到中间
        return r;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }


    /*
    思路： 利用快排的思想来解这道题目， 每次排序，我们要找到这样一个pivot的位置pos， 使得pos左边的都比pivot要大， 
    pos右边的都比pivot要小。 此时如果 
    1. pos+1==k的话，pos位置上的元素也就是第k个元素。 
    2. pos+1k的话，需要往左边找,[left, pos-1]的范围
    */
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k < 0) return -1;
        return quickSort(nums, k, 0, nums.length - 1);    
    }
 
    public int quickSort(int[] nums, int k, int left, int right) {
        if (left >= right) return nums[right];
        int pivot = nums[left];
        int pos = left;
        for (int i = pos + 1; i <= right; i++) {
            if (nums[i] > pivot) {
                pos++;
                swap(nums, i, pos);
            }
        }
        swap(nums, pos, left); // swap the pivot and last element
        if (pos + 1 == k) {
            return nums[pos];
        } else if (pos + 1 < k) {
            return quickSort(nums, k, pos + 1, right );
        } else {
            return quickSort(nums, k, left, pos - 1);
        }
 
    }
}
