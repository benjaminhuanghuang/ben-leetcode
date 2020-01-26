/*
18. 4Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 88768
Total Submissions: 355065
Difficulty: Medium
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

public class Solution018 {
    // public IList<IList<int>> FourSum_Wrong(int[] nums, int target) {
    //     var res = new List<IList<IList<int>>>();
    //     Array.Sort(nums);
    //     var dic = new Dictionary<int, HashSet<int>>();
    //     for (int i = 0; i < nums.Length; i++)
    //     {
    //         for (int j = i +1; j < nums.Length; j++)
    //         {
    //             int sum = nums[i] + nums[j];
    //             if (dic.ContainsKey(target - sum))
    //             {
    //                 foreach(var entry in dic[target - sum])
    //                 {
    //                     List<int> l = new List<int>(entry); 
    //                     l.Add(nums[i]);
    //                     l.Add(nums[j]);
    //                     res.Add(l);
    //                 } 
    //             }
    //         }
    //         for (int j = 0; j < i; j++)
    //         {
    //             int half = nums[i] + nums[j]; 
    //             if (!dic.ContainsKey(half))
    //             {
    //                 dic[half] = new HashSet<List<int>>();   
    //             }
                
    //             dic[half].Add(new List<int>{nums[j], nums[i]});
    //         }
    //     }

    //     return res;
    // }

    public IList<IList<int>> FourSum(int[] nums, int target)   
    {  
        if(nums == null || nums.Length < 4){  
            return new List<IList<int>>();  
        }  
          
        var dic = new Dictionary<string, List<int>>();  
        Array.Sort(nums);
        var list = new List<int>(nums);  
          
        var len = list.Count;  
        for(var j = 0;j < len ; j++)  
        {  
            var d = list[j];  
            for (var i = 0 ;i <= len - 3 ;i++)  
            {     
                var a = list[i];  
                var start = i+1;  
                var end = len-1;  
                if(i == j)
                {  
                    continue;  
                }  
                  
                while (start < end)  
                {  
                    if(start == j){  
                        start ++;   
                        continue;  
                    }  
                    if(end == j){  
                        end --;  
                        continue;  
                    }  
                      
                    var b = list[start];  
                    var c = list[end];  
                      
                    if (a+b+c+d == target) {  
      
                        var v = new List<int>(){a,b,c,d}.OrderBy(x=>x).ToList();  
                        var k = string.Join(",",v);  
                        if(!dic.ContainsKey(k)){  
                            dic.Add(k,v);  
                        }  
                        start ++;  
                        end --;  
                    }  
                    else if (a+b+c+d > target){  
                        end --;  
                    }  
                    else{  
                        start ++;  
                    }  
                }  
            }  
        }  
          
          
        var ret = new List<IList<int>>();  
        foreach(var kv in dic){  
            ret.Add(kv.Value);  
        }  
          
        return ret;  
    }  
}