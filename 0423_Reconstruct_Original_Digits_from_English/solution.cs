/*
423. Reconstruct Original Digits from English [Medium  ]

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the 
digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid 
inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/
using System;
using System.Text;
using System.Collections.Generic;

public class Solution423 {
    //http://blog.csdn.net/u010167269/article/details/52831177
    //http://www.voidcn.com/blog/feiniao198751/article/p-6241897.html
    // 如果字符串含有 z,  则根据题目条件字符串总是有效的来看，必有一个  zero的组合在原串中，那么取出一个zero, 记录0的出现次数加1,
    // 再次循环，直至没有z为止。
    // 出现w，必有two,  出现u，必有four ,出现x，必有six , 出现g,必有 eight
    // 以上完成后，剩下的数字仅仅剩下 one,  five, seven, three, nine, 此时只需要在剩下的找标志性支付，
    // f : five,  s : seven, h: three, o : one
    // 最后一轮，只剩nine，查找结束。以下为代码实现。

    public string OriginalDigits(string s) {
        var charDic = new Dictionary<char, int>();
        
        foreach (char c in s)
        {
            if(!charDic.ContainsKey(c))
                charDic.Add(c, 1);
            else
                charDic[c]++;

        }
        var digits = new List<int>{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        var key = new List<char>{'z','w','u','x','g','o','r','f','v','i'};
        var nums = new List<string>{"zero", "two", "four", "six", "eight","one", "three", "five", "seven", "nine"};
        
        var charCounter = new int[10];
        for(int i =0; i < 10; i ++)
        {
            // how many 'z'
            if (charDic.ContainsKey(key[i]))
            {
                int keyCount = charDic[key[i]];
                if (keyCount > 0)
                {
                    charCounter[digits[i]] = keyCount;   
                    foreach(var c in nums[i])
                    {
                        charDic[c] = charDic[c] - charCounter[digits[i]];
                    }
                }
            }
        }
        
        var sb = new StringBuilder();
        for (int i =0; i< 10;i ++)
            for (int j =0; j< charCounter[i] ;j ++)
                sb.Append(i.ToString());

        return sb.ToString();
    }
    //http://bookshadow.com/weblog/2016/10/16/leetcode-reconstruct-original-digits-from-english/
    //six, zero, two, eight, seven, four中分别包含唯一字母 x, z, w, g, v, u,
    //因此6, 0, 2, 8, 7, 4需要排在其余数字之前。
    public string OriginalDigits_2(string s) {
        // cnts = collections.Counter(s)
        var charDic = new Dictionary<char, int>();
        foreach (char c in s)
        {
            if(charDic.ContainsKey(c))
                charDic[c]++;
            else 
                charDic.Add(c, 1);
        }
        
        // numc = [collections.Counter(num) for num in nums]
        var nums = new List<string>{"six", "zero", "two", "eight", "seven", "four", "five", "nine", "one", "three"};
        var numDic = new Dictionary<string, int>();
        foreach (string num in nums)
        {
            numDic.Add(num, 1);
        }
        var digits = new List<int>{6, 0, 2, 8, 7, 4, 5, 9, 1, 3};
        return "";
        // ans = [0] * 10
        // for idx, num in enumerate(nums):
        //     cntn = numc[idx]
        //     t = min(cnts[c] / cntn[c] for c in cntn)
        //     ans[digits[idx]] = t
        //     for c in cntn:
        //         cnts[c] -= t * cntn[c]
        // return ''.join(str(i) * n for i, n in enumerate(ans))
    }
}