/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/
using System.Collections.Generic;

public class Solution347 {
    public IList<int> TopKFrequent(int[] nums, int k) {
        var dic = new Dictionary<int, int>();

        for (int i =0; i< nums.Length; i++)
        {
            if(dic.ContainsKey(nums[i]))
                dic[nums[i]] ++;
            else
                dic.Add(nums[i], 1);
        }
        //根据每个数字出现的次数把数字放到相应的桶里,统计完之后,依次从编号最大的桶开始依次取数。
        List<int>[] bucket = new List<int>[nums.Length+1];
        foreach (var kv in dic)
        {
            if (bucket[kv.Value] == null)
                bucket[kv.Value] = new List<int>();
            bucket[kv.Value].Add(kv.Key); 
        } 
        List<int> res = new List<int>();
        for( int i = bucket.Length -1; i>=0; i--)
        {   
            if (bucket[i] != null)
            {
                foreach(var num in bucket[i])
                {
                    if (res.Count < k)
                        res.Add(num);
                    else 
                        return res;
                }
            }
        }
        return res;
    }
}
