/*
373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]

*/
using System;
using System.Collections.Generic;


public class Solution373 {
    // Time Limit Exceeded O(mn log(mn))
    public IList<int[]> KSmallestPairs_Naive(int[] nums1, int[] nums2, int k) {
        List<int[]> res = new List<int[]>();
        for (int i = 0; i < Math.Min(nums1.Length, k); ++i) {
            for (int j = 0; j < Math.Min(nums2.Length, k); ++j) {
                res.Add(new int[]{nums1[i], nums2[j]});
            }
        }
        res.Sort((x,y)=>{return (x[0]+x[1]).CompareTo(y[0]+ y[1]);});
        if (res.Count > k) 
            res.RemoveRange(k, res.Count - k);
        return res;
    }

    //http://blog.csdn.net/qq508618087/article/details/51864835
    //记录一下nums1中每个数对应nums2中组合的位置.
    public IList<int[]> KSmallestPairs(int[] nums1, int[] nums2, int k) { 
        int len1 = nums1.Length, len2 = nums2.Length, cnt = Math.Min(k, len1*len2);  
        int[] index = new int[len1];  
        List<int[]> ans = new List<int[]>();  

        while(cnt-- > 0)  
        {  
            int temMin = int.MaxValue, m = 0;  
            for(int i =0; i < len1; i++)  
                if(index[i] < len2 && nums1[i]+nums2[index[i]] < temMin)
                {
                    temMin= nums1[i]+nums2[index[i]];
                    m = i;
                }  
            ans.Add(new int[]{nums1[m], nums2[index[m]++]});  
        }  
        return ans;  
    }  
}