/*
154. Find Minimum in Rotated Sorted Array II

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.


*/


/*
Solution : Use Binary Search to do it. if duplicates allowed, then extra check needed.

nums[mid] > nums[low]: we need to compare low with what we found in the right part, low = mid +1
nums[mid] < nums[low]: include mid in the following search, since mid could be the lowest
nums[mid] = nums[low]: no clue for this case, but we can be sure that we can find minimum in low + 1 to high
           (if low is minimum, mid is minimum too.).
*/
public class Solution154 {
    public int FindMin(int[] nums) {
        var low = 0;
        var high = nums.Length - 1;

        while (low < high)
        {
            if (nums[low] < nums[high]) 
                return nums[low];
            var mid = (high - low) / 2 + low;

            if (nums[mid] < nums[low])             
            {                 
                high = mid;             
            }             
            else if (nums[mid] > nums[low])
            {
                low = mid + 1;
            }
            else
            {
                low++;
            }
        }
        return nums[low];
    }
}
