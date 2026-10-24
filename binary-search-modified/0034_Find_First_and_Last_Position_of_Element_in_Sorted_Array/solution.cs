/*
34. Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

public class Solution034 {
    public int[] SearchRange(int[] nums, int target) {
        if (nums == null || nums.Length < 1)
            return new int[]{-1, -1};

        int left = 0;
        int right = nums.Length -1;
        int[] result = new int[]{-1,-1};
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid +1;
            else  // mid == target, expand the range
            {    
                result[0] = mid;
                result[1] = mid;
                int i = mid -1;
                while(i >= 0 && nums[i] == target)
                {
                    result[0] = i;
                    i -- ;
                }
                i = mid +1;
                while(i < nums.Length && nums[i] == target)
                {
                    result[1] = i;
                    i ++ ;
                }
                break;
            }
        }
        return result;
    }
}