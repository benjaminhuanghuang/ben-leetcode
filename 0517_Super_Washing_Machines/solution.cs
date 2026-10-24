/*
http://bookshadow.com/weblog/2017/02/19/leetcode-super-washing-machines/
给定一个长度为n的整数数组nums，每一次选择m个数(1 ≤ m ≤ n)进行移动：将这m个数-1，同时令其相邻元素+1
（这m个数同时可以是被加元素）
求最少需要多少次移动，使得nums的所有元素均相等。如果不能，则返回-1。


https://discuss.leetcode.com/topic/79938/very-short-easy-java-o-n-solution
For example, your machines[] is [0,0,11,5]. 
So your total is 16 and the target value for each machine is 4. 
Convert the machines array to a kind of gain/lose array, we get: [-4,-4,7,1]. 
Now what we want to do is go from the first one and try to make all of them 0.
To make the 1st machines 0, you need to give all its "load" to the 2nd machines.
So we get: [0,-8,7,1]
then: [0,0,-1,1]
lastly: [0,0,0,0], done.

You don't have to worry about the details about how these machines give load to each other. 
In this process, the least steps we need to eventually finish this process is determined by the 
peak of abs(cnt) and the max of "gain/lose" array. 
In this case, the peak of abs(cnt) is 8 and the max of gain/lose array is 7. So the result is 8.

Some other example:
machines: [0,3,0]; gain/lose array: [-1,2,-1]; max = 2, cnt = 0, -1, 1, 0, its abs peak is 1. So result is 2.
machines: [1,0,5]; gain/lose array: [-1,-2,3]; max = 3, cnt = 0, -1, -3, 0, its abs peak is 3. So result is 3.
 */

using System;
using System.Collections;
using System.Linq;

public class Solution517
{
    public int FindMinMoves(int[] machines)
    {
        int sum = machines.Sum();
        int count = machines.Length;

        if (sum % count != 0)
            return -1;

        int average = sum / count;
        int ans = 0;
        int total = 0;
        foreach (int dress in machines)
        {
            total += (dress - average);  // peak
            ans = Math.Max(ans, Math.Max(Math.Abs(total), dress - average));
        }
        return ans;
    }
}