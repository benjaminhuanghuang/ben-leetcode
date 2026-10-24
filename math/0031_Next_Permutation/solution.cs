/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

reference :
    // https://miafish.wordpress.com/2015/01/30/leetcode-oj-c-next-permutation/
    http://www.cnblogs.com/etcow/archive/2012/10/02/2710083.html
    1. 547532    find falling edge 4
    2. 547532    find 5 should be swped with 4, get 557432
    3. 557432    reverse 7432, get 552347 finally.
*/
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