package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
 */
public class LC_0229_MajorityElement_II {
    /*
    // http://www.cnblogs.com/grandyang/p/4606822.html
    // 任意一个数组出现次数大于n/3的众数最多有两个

     */
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int m = 0, n = 0, cm = 0, cn = 0;
        for (int a : nums)
        {
            if (a == m) ++cm;
            else if (a ==n) ++cn;
            else if (cm == 0) { m = a;  cm = 1;}
            else if (cn == 0) { n = a; cn = 1;}
            else { --cm; --cn;}
        }
        cm = cn = 0;
        for (int a : nums) {
            if (a == m) ++cm;
            else if (a == n) ++cn;
        }
        if (cm > nums.length / 3) res.add(m);
        if (cn > nums.length / 3) res.add(n);
        return res;
    }
}
