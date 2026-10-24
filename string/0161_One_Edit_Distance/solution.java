package cn.huang.leetcode;
/*
161 One Edit Distance
 */
public class LC_0161_OneEditDistance {
    /*
    1. 两个字符串的长度之差大于1，那么直接返回False

    2. 两个字符串的长度之差等于1，那么长的那个字符串去掉一个字符，剩下的应该和短的字符串相同

    3. 两个字符串的长度之差等于0，那么两个字符串对应位置的字符只能有一处不同。

     */
    public boolean isOneEditDistance(String s, String t) {
        // 让s指向长的字符串
        if (s.length() < t.length()) {
            String tmp = s;
            s = t;
            t = tmp;
        }
        int m = s.length();
        int n = t.length();
        int diff = m - n;// diff>=0
        // 两个字符串的长度之差大于1，那么直接返回False
        if (diff >= 2) {
            return false;
            // 两个字符串的长度之差等于1，那么长的那个字符串去掉一个字符，
            // 剩下的应该和短的字符串相同
        } else if (diff == 1) {
            // 小于长度小的
            for (int i = 0; i < n; i++)
                // 到了i，说明0~i-1字符相等，
                // 只要判断剩下的是否相等即可
                if (s.charAt(i) != t.charAt(i))
                    // s去掉一个字符，而t不变
                    return s.substring(i + 1) == t.substring(i);

        } else {
            // 两个字符串的长度之差等于0，
            // 那么两个字符串对应位置的字符只能有一处不同。
            int cnt = 0;
            for (int i = 0; i < n; ++i)
                if (s.charAt(i) != t.charAt(i))
                    ++cnt;
            return cnt == 1;
        }
        return true;

    }
}
