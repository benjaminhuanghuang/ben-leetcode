using System;
using System.Collections.Generic;

//http://blog.csdn.net/mebiuw/article/details/52511992
public class Solution398 {
    private List<int> nums; 
    public Solution398(List<int> nums) {
       this.nums = nums;
    }
    
    public int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < nums.Count; ++i) {
            if (nums[i] != target) continue;
            ++cnt;
            Random rnd = new Random();
            if (rnd.Next() % cnt == 0) 
                res = i;
        }
        return res;
    }
};
