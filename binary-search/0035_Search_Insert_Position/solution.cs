public class Solution035 {
    public int SearchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.Length-1;

        while (start + 1 < end)  //Note!
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid;
        }
        if (nums[start] >= target)
            return start;
        if (nums[end]>=target)
            return end;
        return nums.Length;
    }
    //  Let us consider when the binary search will stop, it will only stop in this two cases.
    // low > high: then we could not find anything, return low.
    // low == high: then we compare target with A[low] to decide where to insert
    private int searchInsert_Recursion(int[] A, int target, int low, int high)
	{
		if (high < low) return low; 		
        if (low == high)  // there is only one element
        { 			
            return A[low] <= target ? low + 1 : low;
		}

		int mid = (high - low) / 2 + low;
		if (A[mid] == target) 
            return mid;
		else if (A[mid] < target)		                         
            return searchInsert_Recursion(A, target, mid + 1, high);                 
        else //if (A[mid] > target)
			return searchInsert_Recursion(A, target, low, mid - 1);
	}

    public int SearchInsert_2(int[] nums, int target) {
        var low = 0;
        var high = nums.Length - 1;
        // for low == high condition, it is already included in low > high condition.
        // low > high: then we could not find anything, return low.
        while(low <= high)
        {
            var mid = (high - low) / 2 + low;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
}