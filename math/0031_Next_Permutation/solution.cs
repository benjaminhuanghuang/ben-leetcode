using System;

public class Solution031
{
    public void NextPermutation(int[] nums) {
        int turnPoint = nums.Length - 2;
        // from right to left find "First" number it is less than the adjact number at right side
        while (turnPoint >=0)
        {
            if (nums[turnPoint] <  nums[turnPoint + 1])
                break;
            turnPoint --;
        }
        // if all number arranges descending, sort (ascending order) and return
        if (turnPoint < 0)
        {
            Array.Sort(nums);
            return;
        }
        // The right section of the numbers are in descending order
        // find smallest number (bigger than nums[turnPoint])in the right section of the numbers
        var nextminlarge = nums.Length - 1;
        while (nextminlarge > turnPoint )
        {
            if (nums[nextminlarge] > nums[turnPoint])
            {
                break;
            }
            nextminlarge--;
        }

        this.SwapElements(nums, turnPoint, nextminlarge);
        this.ReverseElementsBetween(nums, turnPoint+1, nums.Length - 1);   
    }
    private void SwapElements(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    private void ReverseElementsBetween(int[] nums, int start, int end)
    {
        while (end > start)
        {
            int temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
            end--;
            start++;
        }
    }
}