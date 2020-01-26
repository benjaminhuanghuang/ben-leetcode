/*
349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/
using System;
using System.Linq;
using System.Collections.Generic;
public class Solution349 {
    public int[] Intersection(int[] nums1, int[] nums2) {
        Array.Sort(nums1);
        Array.Sort(nums2);
        
        int i = 0, j = 0;
        int[] temp = new int[nums1.Length];
        int index = 0;
        while (i < nums1.Length && j < nums2.Length) {
            if (nums1[i] == nums2[j]) {
                if (index == 0 || temp[index - 1] != nums1[i]) 
                {
                    temp[index++] = nums1[i];
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        int[] result = new int[index];
        for (int k = 0; k < index; k++) {
            result[k] = temp[k];
        }
        
        return result;
    }

     public int[] Intersection_2(int[] nums1, int[] nums2) {
        HashSet<int> set1 = new HashSet<int>(nums1);
        HashSet<int> set2 = new HashSet<int>();
        foreach (int i in nums2){
            if(set1.Contains(i)){
                set2.Add(i);
            }
        }
        return set2.ToArray();
     }
}