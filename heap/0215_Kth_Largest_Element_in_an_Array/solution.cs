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