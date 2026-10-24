package cn.huang.leetcode;
/*

153. Find Minimum in Rotated Sorted Array


 */
public class LC_0153_FindMinimuminRotatedSortedArray {

    /*
        if the mid is greater than low and high, mid is in front of pivot, search from mid to high;
        otherwise, search from low to mid; Special case is the array is sorted(1, 2, 3, 4,…), and
        mid point to the first element of the array(1), so recursively find left part should include
        mid itself.
    */
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length - 1;

        while (low <= high)
        {
            if (low == high)
                return nums[low];
            int mid = (high - low)/2 + low;
            if (nums[mid] > nums[high])  // mid located in left part (bigger part)
            {
                //search from mid to high
                low = mid + 1;
            }
            else
            {   //search from low to mid
                high = mid;
            }
        }

        return Integer.MAX_VALUE;
    }
}
