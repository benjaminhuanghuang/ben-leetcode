/*
228. Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


using System.Collections.Generic;

public class Solution228 {
    // 两个指针 start, end.  如果nums[end+1] = nums[end]+1, 就移动end指针, 
    // 否则, 插入字符串nums[start]->nums[end]. 
    public IList<string> SummaryRanges(int[] nums) {
        var res = new List<string>();  
        if(nums==null || nums.Length<1) 
            return res;  
          
        int start = 0, end = 0;  
        while(end < nums.Length) 
        {  
            if( end + 1 < nums.Length && nums[end + 1] == nums[end] + 1) {  
                end ++;  
            } 
            else 
            {  
                if(start == end) {  
                    res.Add(nums[start].ToString());  
                } 
                else 
                {  
                    string str = nums[start] + "->" + nums[end];  
                    res.Add(str);  
                }  
                ++end;  
                start = end;  
            }  
        }  
        return res;  
    }
}