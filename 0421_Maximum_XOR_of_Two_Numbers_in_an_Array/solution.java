package cn.huang.leetcode;

import java.util.HashSet;

/*
421. Maximum XOR of Two Numbers in an Array
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

 */
public class LC_0421_MaximumXORofTwoNumbersinanArray {
    /*
    https://kingsfish.github.io/2017/12/15/Leetcode-421-Maximum-XOR-of-Two-Numbers-in-an-Array/
     */
    public int findMaximumXOR(int[] nums) {
        int max = 0;
        int mask = 0;
        for(int i = 31; i >= 0; i --){
            // 为获取前n位的临时变量
            mask = mask | (1 << i);
            HashSet<Integer> set = new HashSet<>();
            for(int num : nums){
                // 将所有数字的前n位放入set中
                set.add(mask & num);
            }
            // 假定第n位为1,前n-1位max为之前迭代求得
            int tmp = max | (1 << i);
            for(int pre : set){
                // 查看`b`是否在
                if(set.contains(tmp ^ pre)){
                    // b存在，第n位为1
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
}
