package cn.huang.leetcode;

/*
    520. Detect Capital
 */
public class LC_0520_DetectCapital {
    public boolean detectCapitalUse(String word) {
        String lower = word.toLowerCase();
        if (lower.equals(word)) {
            return true;
        }

        String upper = word.toUpperCase();
        if (upper.equals(word)) {
            return true;
        }

        String str = word.substring(1);
        return str.equals(str.toLowerCase());
    }
}
