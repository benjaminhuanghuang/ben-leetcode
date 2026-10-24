/*
153. Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.


*/
public class Solution153 {
    /*  
        if the mid is greater than low and high, mid is in front of pivot, search from mid to high; 
        otherwise, search from low to mid; Special case is the array is sorted(1, 2, 3, 4,…), and 
        mid point to the first element of the array(1), so recursively find left part should include 
        mid itself.
    */
    public int FindMin(int[] nums) {
        var low = 0;
        var high = nums.Length - 1;

        while (low <= high)             
        {                 
            if (low == high) 
                return nums[low];                 
            var mid = (high - low)/2 + low;                 
            if (nums[mid] > nums[high])  // mid located in left part (bigger part)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;   
            }
        }

        return int.MaxValue;
    }
}