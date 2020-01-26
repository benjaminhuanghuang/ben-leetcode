package cn.huang.leetcode;

/*
    91. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/


/*
    https://leetcode.com/problems/decode-ways/

    Facebook Coding Interview Question - How Many Ways to Decode This Message?
    https://www.youtube.com/watch?v=qli-JCrSwuk


    "a" -> 1
    "b" -> 2
    ...

    "12" -> ab
    "12" -> l

    Analysis:
    case 1: "12345" -> "a" + decode("2345") or "l" + decode("345")
    so
        num_ways("12345") = num_ways("2345") + num_ways("345")

    case 2: "27345" -> "b" + decode("7345")
    so
        num_ways("27345") = num_ways("7345")

    case 3: num_ways("011") = 0

 */


/*
Lai Offer
https://www.youtube.com/watch?v=ZLwwc3-vVP4&t=74s

 */
public class LC_0091_DecodeWays {
    // To case "111111", h(6) = h(5) + h(4), h(5) = h(4) + h(3)... h(4) were calculated twice
    public int numDecodings_recursive(String s) {
        return this.helper(s, s.length());

    }

    private int helper(String s, int restLetters) {
        if (restLetters == 0)
            return 1;

        int startIndex = s.length() - restLetters;
        if (s.charAt(startIndex) == '0')
            return 0;
        int result = helper(s, restLetters - 1);

        // (data.charAt(startIndex) != '0') can guarantee Integer.parseInt(data.substring(startIndex, startIndex + 2)) >= 10
        if (restLetters >= 2 && Integer.parseInt(s.substring(startIndex, startIndex + 2)) <= 26) {
            result += this.helper(s, restLetters - 2);
        }

        return result;
    }

    public int numDecodings_dp(String s) {
        if (s == null || s.length() == 0 || s.charAt(0) == '0')
            return 0;
        if (s.length() == 1)
            return 1;

        int[] dp = new int[s.length()];
        dp[0] = 1;

        if (Integer.parseInt(s.substring(0, 2)) > 26) {
            if (s.charAt(1) != '0') {
                dp[1] = 1;
            } else {
                dp[1] = 0;
            }
        } else {
            if (s.charAt(1) != '0') {
                dp[1] = 2;
            } else {
                dp[1] = 1;
            }
        }

        for (int i = 2; i < s.length(); i++) {
            if (s.charAt(i) != '0') {
                dp[i] += dp[i - 1];
            }

            int val = Integer.parseInt(s.substring(i - 1, i + 1));
            if (val <= 26 && val >= 10) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.length() - 1];

    }
}
