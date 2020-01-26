package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
    594. Longest Harmonious Subsequence
 */
public class LC_0594_LongestHarmoniousSubsequence {

    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            // getOrDefault（JDK 8）
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int max = 0;
        for (int num : map.keySet()) {
            // 如果map包括num+1，那么比较当前值
            if (map.containsKey(num + 1)) {
                int tmp = map.get(num) + map.get(num + 1);
                max = Math.max(max, tmp);
            }
        }
        return max;
    }
}
