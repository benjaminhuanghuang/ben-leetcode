/*
91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/
/*
http://blog.csdn.net/worldwindjp/article/details/19938131

定义数组number，number[i]意味着：字符串s[0..i-1]可以有number[i]种解码方法。
回想爬楼梯问题一样，number[i] = number[i-1] + number[i-2]
但不同的是本题有多种限制：
第一： s[i-1]不能是0，如果s[i-1]是0的话，number[i]就只能等于number[i-2]
第二，s[i-2,i-1]中的第一个字符不能是0，而且Integer.parseInt(s.substring(i-2,i))获得的整数必须在0到26之间。

*/
public class Solution091 {
    //dp[i] = how many ways it can decoded from 0 to i. 
    //so if s[i] is 1 to 9,  then dp[i] can be decoded the same number of way dp[i – 1] has; 
    // if string at i – 1 and i is between 10 to 26, then dp[i] can be decoded the same number of way dp[i – 2] has.
    // if s[i] = 0, dp[i] = dp[i-2]
    // if s[i] !=0, dp[i] = dp[i-1]
    // if 10 < int(s[i - 2] + s[i - 1])<=26, dp[i] = dp[i-1] + dp[i-2]
    public int NumDecodings(string s) {
        if (string.IsNullOrEmpty(s) || s[0]=='0')
        {
            return 0;
        }
        var dp = new int[s.Length + 1];
        dp[0] = 1;
        dp[1] = 1;
        // 
        for (int i = 2; i < s.Length + 1; i++)
        {                 
            if (10 < int.Parse(s.Substring(i - 2, 2)) && int.Parse(s.Substring(i - 2, 2))<= 26 && s[i-1] != '0')
                dp[i] = dp[i -1] + dp[i-2];
            else if(10 == int.Parse(s.Substring(i - 2, 2)) || 20 == int.Parse(s.Substring(i - 2, 2)))
                dp[i] = dp[i-2];
            else if(s[i-1] != '0')
                dp[i] = dp[i-1];
            else
                return 0;
        }

        return dp[s.Length];
    }
}