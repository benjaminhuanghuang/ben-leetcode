package cn.huang.leetcode;
/*
517. Super Washing Machines

You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one
of its adjacent washing machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you
should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not
possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation:
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3
3rd move:    2     1 <-- 3    =>    2     2     2

Example2

Input: [0,3,0]

Output: 2

Explanation:
1st move:    0 <-- 3     0    =>    1     2     0
2nd move:    1     2 --> 0    =>    1     1     1

Example3

Input: [0,2,0]

Output: -1

Explanation:
It's impossible to make all the three washing machines have the same number of dresses.

Note:

    The range of n is [1, 10000].
    The range of dresses number in a super washing machine is [0, 1e5].

 */

/*
https://blog.csdn.net/TstsUgeg/article/details/62427718

给定一个长度为n的整数数组nums，每一次选择m个数(1 ≤ m ≤ n)进行移动：将这m个数-1，同时令其相邻元素+1（这m个数同时可以是被加元素）

求最少需要多少次移动，使得nums的所有元素均相等。如果不能，则返回-1。
 */

import static java.lang.Math.abs;

public class LC_0517_SuperWashingMachines {
    public int findMinMoves(int[] machines) {
        if (machines.length == 0)
            return 0;
        int n = machines.length;
        int minMv = Integer.MIN_VALUE;
        int avg;

        int[] sum = new int[n + 1];

        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + machines[i];
        if (sum[n] % n != 0)
            return -1;
        avg = sum[n] / n;

        for (int i = 0; i < n; ++i) {
            int lCnt = sum[i] - avg * i;
            int rCnt = sum[n] - sum[i + 1] - avg * (n - 1 - i);
            if (lCnt > 0 && rCnt > 0)
                minMv = Math.max(minMv, Math.max(lCnt, rCnt));
            else if (lCnt < 0 && rCnt < 0)
                minMv = Math.max(minMv, 0 - lCnt - rCnt);
            else
                minMv = Math.max(minMv, Math.max(Math.abs(lCnt), Math.abs(rCnt)));
        }

        return minMv;
    }
}
