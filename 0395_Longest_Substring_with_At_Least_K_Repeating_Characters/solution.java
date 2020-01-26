package cn.huang.leetcode;
/*
395. Longest Substring with At Least K Repeating Characters
 Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every
 character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

 */

/*
题目要求 满足串中每个字符出现次数都不少于k次的最长子串。

首先出现小于k次的字符一定不会出现在要求的子串中，因此统计字符串中每个字符出现的次数，以小于k次的字符为分割点，
将字符串分割为几个小片段。对每个小片段，我们仍需要判断它是否满足每个字符出现次数不小于k，所以对每个小片段递归分割。
终止条件是片段中每个字符次数都不小于k时返回片段长度。

 */
public class LC_0395_LongestSubstringwithAtLeastKRepeatingCharacters {
    public int longestSubstring(String s, int k) {
        if (k <= 1) {
            return s.length();
        }

        int[] repeat = new int['z' + 1];
        for (int i = 0; i < s.length(); i++) {
            repeat[s.charAt(i)]++;
        }
        StringBuilder regex = new StringBuilder("");
        boolean firstSplit = true;
        for (int i = 'a'; i <= 'z'; i++) {
            if (repeat[i] > 0 && repeat[i] < k) {
                if (firstSplit) {
                    regex.append((char) i);
                    firstSplit = false;
                } else {
                    regex.append("|" + (char) i);
                }
            }
        }
        if (regex.length() > 0) {
            //说明有分隔符
            String[] strs = s.split(regex.toString());
            int max = 0;
            int tmpAns = 0;
            for (String str : strs) {
                tmpAns = longestSubstring(str, k);
                if (tmpAns > max) {
                    max = tmpAns;
                }
            }
            return max;
        } else {
            //没有分隔符,说明s中的每一个字符出现的次数都大于等于k
            return s.length();
        }
    }
}
