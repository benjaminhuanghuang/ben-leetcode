/*
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that 
    you cannot load all elements into the memory at once?
*/
using System;

public class Solution350
{
    public int[] Intersect(int[] nums1, int[] nums2)
    {
        Array.Sort(nums1);
        Array.Sort(nums2);

        int i = 0, j = 0;
        int[] temp = new int[nums1.Length];
        int index = 0;
        while (i < nums1.Length && j < nums2.Length)
        {
            if (nums1[i] == nums2[j])
            {
                if (index == 0 || temp[index - 1] != nums1[i])
                {
                    temp[index++] = nums1[i];
                }
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        int[] result = new int[index];
        for (int k = 0; k < index; k++)
        {
            result[k] = temp[k];
        }

        return result;
    }
}