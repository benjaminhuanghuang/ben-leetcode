/*
319. Bulb Switcher

There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn 
off every second bulb. On the third round, you toggle every third bulb (turning on if it's 
off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth 
round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/
using System;

public class Solution319 {
    //可以看出一个数只有被操作奇数次，最终才会亮。
    // 如果n可以分解为a*b，那么在第ａ轮和第ｂ也会被各操作一次。
    // 但是当n = k * k时，只会被操作一次，因此可以知道只有当ｎ可以被分解为一个数的平方的时候才会出现奇数次操作，最终才会保持亮。
    public int BulbSwitch(int n) {
        return (int)Math.Sqrt(n);
    }
}