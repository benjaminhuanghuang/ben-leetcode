/*
229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

using System.Collections.Generic;

public class Solution229 {
    // http://www.cnblogs.com/grandyang/p/4606822.html
    // 任意一个数组出现次数大于n/3的众数最多有两个
    public IList<int> MajorityElement(int[] nums) {
        List<int> res = new List<int>();
        int m = 0, n = 0, cm = 0, cn = 0;
        foreach (var a in nums) 
        {
            if (a == m) ++cm;
            else if (a ==n) ++cn;
            else if (cm == 0) { m = a;  cm = 1;}
            else if (cn == 0) { n = a; cn = 1;}
            else { --cm; --cn;}
        }
        cm = cn = 0;
        foreach (var a in nums) {
            if (a == m) ++cm;
            else if (a == n) ++cn;
        }
        if (cm > nums.Length / 3) res.Add(m);
        if (cn > nums.Length / 3) res.Add(n);
        return res;
    }
}