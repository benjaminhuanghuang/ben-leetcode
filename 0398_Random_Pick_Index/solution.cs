/*
398. Random Pick Index

Given an array of integers with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of 
returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);

http://www.cnblogs.com/grandyang/p/5875509.html

这道题指明了我们不能用太多的空间，
计数器cnt和返回结果res，我们遍历整个数组，如果数组的值不等于target，直接跳过；如果等于target，计数器加1，
然后我们在[0,cnt]范围内随机生成一个数字，如果这个数字是0，我们将res赋值为i即可，

*/
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
