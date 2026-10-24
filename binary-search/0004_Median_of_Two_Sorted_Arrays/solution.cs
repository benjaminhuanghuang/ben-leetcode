/*
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

using System;
using System.Collections;
using System.Linq;

public class Solution004 {
    // O(NlogN)
    public double FindMedianSortedArrays_Naive(int[] nums1, int[] nums2) 
    {
        double answer = 0;
        // Contact in Linq
        int[] combined = nums1.Concat(nums2).ToArray();
        Array.Sort(combined);
        int length = combined.Length;
        if (length % 2 == 0)
        {
            answer = (combined[length/2-1] + combined[length/2]) /2.0;   
        }
        else
        {
             answer = combined[length/2];
        }
        return answer;
    }

    // find (length A + length B) / 2 and (length A + length B) / 2 + 1 if it is even, or 
    // just  (length A + length B) / 2 + 1 if it is odd. 
    // the key question is how to find kth small element in two sorted arrays. 
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        int length = nums1.Length + nums2.Length;
        if (length %2 == 1)
        {
            return this.GetKthNum(nums1, 0,nums2, 0, length/2+1);
        }
        else
        {
            return (this.GetKthNum(nums1, 0, nums2, 0, length/2) + this.GetKthNum(nums1, 0, nums2, 0, length/2+1)) / 2.0 ;
        }
    }

    internal int GetKthNum(int[] nums1, int start1,  int[] nums2, int start2, int k)
    {
        if (start1 >= nums1.Length)  // nums1 is empty
        {
            return nums2[start2 + k - 1];  // return Kth num in nums2
        }
        if (start2 >= nums2.Length)  // nums2 is empty
        {
            return nums1[start1 + k - 1];
        }
        if (k==1)
        {
            return Math.Min(nums1[start1], nums2[start2]);
        }

        // Check if the index out of range
        int keyPos1 = start1 + k/2 - 1;
        int keyPos2 = start2 + k/2 - 1;
        int nums1Key = keyPos1 < nums1.Length ? nums1[keyPos1] : Int32.MaxValue;
        int nums2Key = keyPos2 < nums2.Length ? nums2[keyPos2] : Int32.MaxValue;

        if (nums1Key <= nums2Key)
        {
            return this.GetKthNum(nums1, keyPos1+1, nums2, start2, k - k/2);
        }
        else
        {
            return this.GetKthNum(nums1, start1, nums2, keyPos2+1, k - k/2);    
        }
    }
}