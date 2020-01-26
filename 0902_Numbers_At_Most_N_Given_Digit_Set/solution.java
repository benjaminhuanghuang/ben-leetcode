package cn.huang.leetcode;
/*
902. Numbers At Most N Given Digit Set

 */
public class LC_0902_NumbersAtMostNGivenDigitSet {
    /*

     */
    public int atMostNGivenDigitSet(String[] D, int N) {
        char[] s = String.valueOf(N).toCharArray();
        int n = s.length;
        int ans = 0;
        for (int i = 1; i < n; ++i)
            ans += (int)Math.pow(D.length, i);
        for (int i = 0; i < n; ++i) {
            boolean prefix = false;
            for (String d : D) {
                if (d.charAt(0) < s[i]) {
                    ans += Math.pow(D.length, n - i - 1);
                } else if (d.charAt(0) == s[i]) {
                    prefix = true;
                    break;
                }
            }
            if (!prefix) return ans;
        }
        return ans + 1;
    }
}
