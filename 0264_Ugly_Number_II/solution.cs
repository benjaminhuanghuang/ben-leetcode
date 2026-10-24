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

