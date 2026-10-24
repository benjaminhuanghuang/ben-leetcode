package cn.huang.leetcode;

/*
3. Longest Substring Without Repeating Characters
 */
public class LC_0003_LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0)
            return 0;

        int[] hash = new int[256];
        int begin = 0, end = 0;
        int repeat = 0, res = 0;

        while (end < s.length()) {
            if (hash[s.charAt(end++)]++ > 0) {
                repeat++;
            }

            while (repeat > 0) {
                if (hash[s.charAt(begin++)]-- > 1) {
                    repeat--;
                }
            }
            res = Math.max(res, end - begin);
        }

        return res;
    }
}
