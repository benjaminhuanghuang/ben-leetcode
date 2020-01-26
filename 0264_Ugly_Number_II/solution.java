package cn.huang.leetcode;

import java.util.ArrayList;

/*
264. Ugly Number II
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:

    1 is typically treated as an ugly number.
    n does not exceed 1690.

 */
public class LC_0264_UglyNumber_II {
    public int nthUglyNumber(int n) {
        if(n<=0)
            return 0;

        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(1);

        int i=0;
        int j=0;
        int k=0;

        while(list.size()<n){
            int m2 = list.get(i)*2;
            int m3 = list.get(j)*3;
            int m5 = list.get(k)*5;

            int min = Math.min(m2, Math.min(m3, m5));
            list.add(min);

            if(min==m2)
                i++;

            if(min==m3)
                j++;

            if(min==m5)
                k++;
        }

        return list.get(list.size()-1);
    }
}
