package cn.huang.leetcode;
/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

 */

import java.util.Arrays;

/*
6 5 4 8 7 5 1
如果想要找到下一个排列，找到递增的位置是关键。这里才可以使其增长得更大。
首先肯定从后面开始看，1和5调换了没有用。 7、5和1调换了也没有效果，因此而发现了8、7、5、1是递减的。
如果想要找到下一个排列，找到递增的位置是关键。 因为在这里才可以使其增长得更大。
于是找到了4，比4大的数是5而不是8或者7更不是1。 因此就需要找出比4大但在这些大数里面最小的值，并将其两者调换。
那么整个排列就成了：6 5 5 8 7 4 1 然而最后一步将后面的8 7 4 1做一个递增。

From right to left, find the first digit (PartitionNumber) which violate the increase trend.
From right to left, find the first digit with large than PartitionNumber, call it changeNumber
Swap PartitionNumber and changeNumber
Reverse all digit on the right of partition index
 */
public class LC_0031_NextPermutation {
    public void nextPermutation(int[] nums) {
        int turnPoint = nums.length - 2;
        // from right to left find "First" number it is less than the adjacent number at right side
        while (turnPoint >=0)
        {
            if (nums[turnPoint] <  nums[turnPoint + 1])
                break;
            turnPoint --;
        }
        // if all number arranges descending, sort (ascending order) and return
        if (turnPoint < 0)
        {
            Arrays.sort(nums);
            return;
        }
        // The right section of the numbers are in descending order
        // find smallest number (bigger than nums[turnPoint])in the right section of the numbers
        int nextminlarge = nums.length - 1;
        while (nextminlarge > turnPoint )
        {
            if (nums[nextminlarge] > nums[turnPoint])
            {
                break;
            }
            nextminlarge--;
        }

        this.swapElements(nums, turnPoint, nextminlarge);
        this.reverseElementsBetween(nums, turnPoint+1, nums.length - 1);
    }
    private void swapElements(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    private void reverseElementsBetween(int[] nums, int start, int end)
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
