/*
60. Permutation Sequence

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
using System;
using System.Linq;
using System.Text;

public class Solution060 {
    // http://www.cnblogs.com/zuoyuan/p/3785530.html
    // n! = 1, 2, 6, 24 ,120, 720, 5040
    // when n = 6, k = 5040, answer is 18765432
    // when n = 6, k = 5040 * 2, answer is 28765432
    // 假设n = 6，k = 400
    // 先计算第一位，
    // 第一位为6，那么它最少也是第5! * 5 + 1个排列，这是因为第一位为1/2/3/4/5时，都有5!个排列，因此第一位为6时，至少是第5! * 5 + 1个排列（这个排列为612345）。
    // 5! * 5 + 1 = 601 > k，所以第一位不可能是6.
    // 一个一个地枚举，直到第一位为4时才行，这时，4xxxxx至少为第5! * 3 + 1 = 361个排列。
    // 然后计算第二位，
    // 与计算第一位时的区别在于，46xxxx至少为第4! * 4 + 1 = 97个排列，这是因为比6小的只有5/3/2/1了。
    // 最后可以计算出第二位为2。
    public string GetPermutation(int n, int k) {
        if(n <=0)
            return "";
        var factorial = new int[n];
        factorial[0]= 1;
        for(int i = 1; i< n; i++)
            //n! =0, 1, 2, 6, 24 ,120, 720, 5040
            factorial[i] = i * factorial[i -1];
        
        var res = new StringBuilder();

        // the digits of n : [1,2...n]
        var digits = Enumerable.Range(1, n).ToList();
        for (int i = 1; i <= n; i++)
        {
            //5! * 5 + 1 = 601 =>  index = (k - 1)/factorial[n-1]  
            var index = (k - 1)/factorial[n - i];
            k -= index * factorial[n - i];
            res.Append(digits[index]);
            digits.RemoveAt(index);
        }

        return res.ToString();
    }
}