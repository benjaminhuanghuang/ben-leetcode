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