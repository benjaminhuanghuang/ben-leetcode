package cn.huang.leetcode;

/*
730. Count Different Palindromic Subsequences


 */

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/
 */
public class LC_0730_CountDifferentPalindromicSubsequences {
    private int[][] m_;
    private static final int kMod = 1000000007;

    public int countPalindromicSubsequences(String S) {
        int n = S.length();
        m_ = new int[n][n];
        return count(S.toCharArray(), 0, n - 1);
    }

    private int count(char[] s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (m_[i][j] > 0) return m_[i][j];

        long ans = 0;

        if (s[i] == s[j]) {
            ans += count(s, i + 1, j - 1) * 2;
            int l = i + 1;
            int r = j - 1;
            while (l <= r && s[l] != s[i]) ++l;
            while (l <= r && s[r] != s[i]) --r;
            if (l > r) ans += 2;
            else if (l == r) ans += 1;
            else ans -= count(s, l + 1, r - 1);
        } else {
            ans = count(s, i, j - 1)
                    + count(s, i + 1, j)
                    - count(s, i + 1, j - 1);
        }

        m_[i][j] = (int) ((ans + kMod) % kMod);
        return m_[i][j];
    }
}
