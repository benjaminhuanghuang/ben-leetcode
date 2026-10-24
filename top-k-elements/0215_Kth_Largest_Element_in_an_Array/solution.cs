/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element 
in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

public class Solution215 {
     public int FindKthLargest(int[] nums, int k) {
        return Helper(nums, 0, nums.Length - 1, k);    
    }
    
    private int Helper(int[] nums, int low, int high, int k)
    {
        if (low >= high) 
            return nums[low];

        var pivot = nums[low];
        var pivotIndex = low;
        for (int i = low + 1; i <= high; i++)
        {
            if (nums[i] <= pivot)
            {
                this.Swap(nums, ++low, i);
            }
        }

        this.Swap(nums, pivotIndex, low);

        var rightcount = high - low + 1;
        if (rightcount == k) return pivot;
        else if (k < rightcount)
        {
            return Helper(nums, low + 1, high, k);
        }
        else
        {
            return Helper(nums, pivotIndex, low - 1, k - rightcount);
        }
    }

    private void Swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}