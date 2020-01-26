package cn.huang.leetcode;

// Map<K,V> is an interface, HashMap<K,V> is a class that implements Map
// Funcitons: put(), containsKey()

import java.util.HashMap;
import java.util.Map;

public class LC_0001_TwoSum {
    public static int[] solve(int[] nums, int target) {
        if (nums == null || nums.length < 2)
            return new int[]{0, 0};

        // map<value, index>
        Map<Integer, Integer> visited = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (visited.containsKey(nums[i])) {
                return new int[]{visited.get(nums[i]), i};
            } else {
                visited.put(target - nums[i], i);
            }
        }

        return new int[]{0, 0};
    }


    public static int[] solve2(int[] nums, int target) {
        if (nums == null || nums.length < 2)
            return new int[]{0, 0};

        // map<value, index>
        Map<Integer, Integer> visited = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (visited.containsKey(target - nums[i])) {
                return new int[]{visited.get(target - nums[i]), i};
            } else {
                visited.put(nums[i], i);
            }
        }

        return new int[]{0, 0};
    }
}
