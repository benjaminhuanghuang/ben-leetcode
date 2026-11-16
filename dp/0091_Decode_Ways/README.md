# 91. Decode Ways

<https://leetcode.com/problems/decode-ways/>

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

## Explain

状态定义: dp[i] = 字符串前 i 个字符 s[0..i-1] 的解码方式数。
看前 i 个字符时，最后一个字母只有两种来源：

情况 1：最后 1 位单独解码。 只要 s[i-1] 不是 '0'（0 没有对应字母），就可以把它单独解码成一个字母，前面的 i-1 个字符有 dp[i-1] 种解法，所以加上 dp[i-1]。

情况 2：最后 2 位合起来解码。 如果 s[i-2..i-1] 组成的两位数在 10 到 26 之间，就可以合成一个字母，前面 i-2 个字符有 dp[i-2] 种解法，所以加上 dp[i-2]。下限是 10 而不是 1，是为了排除 "05" 这种带前导 0 的情况。
