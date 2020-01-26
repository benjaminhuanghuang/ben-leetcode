package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
970. Powerful Integers

Given two non-negative integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0
and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.



Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]


 */
public class LC_0970_PowerfulIntegers {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> set = new HashSet<Integer>();
        int max = Math.max(x,y);
        int min = (Math.min(x,y) == 1) ? max : Math.min(x,y);
        int limit = 1;
        if (min != 1) {
            while (Math.pow(bound, 1/(double)limit) >= min) {
                limit = limit +1;
            }
        }
        for (int i =0; i <= limit; i++) {
            for(int j=0; j <=limit; j++) {
                int sum = (int) (Math.pow(x,i) + Math.pow(y,j));
                if (sum <= bound){
                    set.add(sum);
                }
            }
        }
        return new ArrayList(set);
    }
}
