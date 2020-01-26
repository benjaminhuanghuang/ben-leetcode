package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

 */
public class LC_0347_TopKFrequentElements {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> dic = new HashMap<>();   // number: times

        for (int i = 0; i < nums.length; i++) {
            if (dic.containsKey(nums[i]))
                dic.put(nums[i], dic.get(nums[i]) + 1);
            else
                dic.put(nums[i], 1);
        }

        //根据每个数字出现的次数把数字放到相应的桶里,统计完之后,依次从编号最大的桶开始依次取数。
        List<Integer>[] bucket = new ArrayList[nums.length + 1];
        for (Map.Entry<Integer, Integer> kv : dic.entrySet()) {
            if (bucket[kv.getValue()] == null)
                bucket[kv.getValue()] = new ArrayList<Integer>();
            bucket[kv.getValue()].add(kv.getKey());
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (int i = bucket.length - 1; i >= 0; i--) {
            if (bucket[i] != null) {
                for (int num : bucket[i]) {
                    if (res.size() < k)
                        res.add(num);
                    else
                        return res;
                }
            }
        }
        return res;
    }
}
