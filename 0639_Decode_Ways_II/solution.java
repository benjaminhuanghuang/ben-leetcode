package cn.huang.leetcode;

/*
639. Decode Ways II

 A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:

Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

Example 2:

Input: "1*"
Output: 9 + 9 = 18

Note:

    The length of the input string will fit in range [1, 105].
    The input string will only contain the character '*' and digits '0' - '9'.

 */
public class LC_0639_DecodeWays_II {
    final int MOD = 1000000007;

    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        // State & Initialize
        int len = s.length();
        long[] dp = new long[len + 1];    // we should use long array here to avoid overfolw Integer
        dp[0] = 1;
        dp[1] = s.charAt(0) == '*' ? 9 : s.charAt(0) != '0' ? 1 : 0;

        // Function
        for (int i = 2; i <= len; i++) {
            if (s.charAt(i - 1) == '*') {
                dp[i] = 9 * dp[i - 1];
                if (s.charAt(i - 2) == '1') {
                    dp[i] = (dp[i] + 9 * dp[i - 2]) % MOD;
                } else if (s.charAt(i - 2) == '2') {
                    dp[i] = (dp[i] + 6 * dp[i - 2]) % MOD;
                } else if (s.charAt(i - 2) == '*') {
                    dp[i] = (dp[i] + 15 * dp[i - 2]) % MOD;
                }
            } else {
                // if s.charAt(i-1) != '*' && s.charAt(i-1) != '0', => s[i-1] could be decode as a character.
                // then dp[i] = dp[i-1]
                // if s.charAt(i-1) == '0', => s[i-1] couldn't be decoded as a character
                // it means it can't make any contributions to the result, so dp[i] = 0
                dp[i] = s.charAt(i - 1) != '0' ? dp[i - 1] : 0;
                if (s.charAt(i - 2) == '1') {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
                } else if (s.charAt(i - 2) == '2' && s.charAt(i - 1) <= '6') {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
                } else if (s.charAt(i - 2) == '*') {
                    dp[i] = (dp[i] + (s.charAt(i - 1) <= '6' ? 2 : 1) * dp[i - 2]) % MOD;
                }
            }
        }

        return (int) dp[len];
    }
}
