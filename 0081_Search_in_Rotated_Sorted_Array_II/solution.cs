/*
81. Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Refer to 33. Search in Rotated Sorted Array
*/

public class Solution081 {
    public bool Search(int[] nums, int target) {
        int index =  this.SearchInRotatedArrayRecursion(nums, 0, nums.Length-1, target);
        return index >=0;
    }

    private int SearchInRotatedArrayRecursion(int[] array, int low, int high, int x)
    {          
        if (low > high)
        {
            return -1;
        }
        var mid = (high - low) / 2 + low;
        if (array[mid] == x)
        {
            return mid;
        }

        // left part is increasing
        if (array[mid] > array[low])
        {
            if (x >= array[low] && x < array[mid])
            {
                return this.SearchInRotatedArrayRecursion(array, low, mid - 1, x);
            }
            else
            {
                return this.SearchInRotatedArrayRecursion(array, mid + 1, high, x);
            }
        }
        // right part is increasing
        else if (array[mid] < array[low])             
        {                 
            if (x > array[mid] && x <= array[high])
            {
                return this.SearchInRotatedArrayRecursion(array, mid + 1, high, x);
            }
            else
            {
                return this.SearchInRotatedArrayRecursion(array, low, mid - 1, x);
            }
        }
        // left part are all same, just increase low by 1
        else
        {
            return this.SearchInRotatedArrayRecursion(array, low + 1, high, x);
        }
    }
}