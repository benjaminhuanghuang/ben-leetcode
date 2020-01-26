/*
421. Maximum XOR of Two Numbers in an Array   [Google]

Given a list of numbers, a[0], a[1], a[2], … , a[N-1], where 0 <= a[i] < 2^32. 
Find the maximum result of a[i] XOR a[j].

Could you do this in O(n) runtime?

Input: [3, 10, 5, 25, 2, 8]
Output: 28

*/
using System.Collections.Generic;

public class Solution421 {
    //https://segmentfault.com/a/1190000007283296
    //利用XOR的性质，a^b = c, 则有 a^c = b，且 b^c = a;
    //所以每次从高位开始，到某一位为止，所能获得的最大的
    //假定在某一位上的任意两数xor能得到的最大值是tmp,那么他一定满足a(xor)b = tmp,
    //其中set.contains(a) && set.contains(b). 所以，我们只需要判断b(xor)tmp的结果是不是在当前这一位下的set内，
    //就可以知道这个tmp能不能由这个set中的任意两个数组成。
    // example: Given [14, 11, 7, 2], which in binary are [1110, 1011, 0111, 0010].
    // Since the MSB is 3, I'll start from i = 3 to make it simplify.
    // i = 3, set = {1000, 0000}, max = 1000
    // i = 2, set = {1100, 1000, 0100, 0000}, max = 1100
    // i = 1, set = {1110, 1010, 0110, 0010}, max = 1100
    // i = 0, set = {1110, 1011, 0111, 0010}, max = 1100
    public int FindMaximumXOR(int[] nums) {
        int max =0, mask=0;
        for(int i =31; i>=0; i--)
        {
            mask = mask | (1<<i);
            HashSet<int> set = new HashSet<int>();
            foreach(int num in nums)
            {
                set.Add(num & mask);
            }
            int tmp = max | (1 << i);
            foreach (var prefix in set)
            {
                if (set.Contains(prefix ^ tmp))
                {
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
}