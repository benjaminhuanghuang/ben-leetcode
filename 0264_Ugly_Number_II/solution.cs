/*
264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are 
not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from 
three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/
using System;
using System.Collections.Generic;

public class Solution264 {
    //https://www.hrwhisper.me/leetcode-ugly-number-i-ii/
    // https://my.oschina.net/Tsybius2014/blog/495962
    public int NthUglyNumber(int n) {
        // 长度为n的数组uglyNumbers，用于从小到大顺序存储n个丑数，数组中的首项为1，即第一个丑数为1
        List<int> uglys = new List<int>();
        uglys.Add(1);
        
        int p2 = 0, p3 = 0, p5 = 0;
        // p2, p3 & p5 share the same queue: uglys
        //找出数组uglyNumbers[p2]*2、uglyNumbers[p3]*3、uglyNumbers[p5]*5的最小值，最小值即为下一个丑数，同时更新最小值对应的下标，
        while(uglys.Count < n){
            uglys.Add(Math.Min(Math.Min(uglys[p2] * 2, uglys[p3] * 3), uglys[p5] * 5));
            int latUgly = uglys[uglys.Count - 1];
            while (uglys[p2] * 2 <= latUgly) p2++;
            while (uglys[p3] * 3 <= latUgly) p3++;
            while (uglys[p5] * 5 <= latUgly) p5++;
        }

        return uglys[uglys.Count - 1];
    }
}

