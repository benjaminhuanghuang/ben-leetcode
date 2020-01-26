package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/*
792. Number of Matching Subsequences

Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".

Note:

    All words in words and S will only consists of lowercase letters.
    The length of S will be in the range of [1, 50000].
    The length of words will be in the range of [1, 5000].
    The length of words[i] will be in the range of [1, 50].


 */

/*
从note中可以看出words的长度不长，而S的长度最大有50000，暴力的做法：每个word去匹配S，因为S没有记忆成高效数据结构，
每次匹配都会重新遍历一次S，时间复杂度为O(len(S))，显然会超时。

所以我们需要对S进行改造，采用dp[i]['a' ~ 'z']表示在S[i]这个位置后，最先出现’a’ ~ ‘z’的下标。这样我们建立了一个O(1)的索引。
可以快速匹配word了。这其中还有贪心的思路，还需细细品味。

 */
public class LC_0792_NumberofMatchingSubsequences {
    public int numMatchingSubseq(String S, String[] words) {
        int n = S.length();
        int[][] dp = new int[n + 1][32];
        for (int i = 0; i < n + 1; ++i)
            Arrays.fill(dp[i], -1);
        for (int i = n - 1; i >= 0; --i)
            dp[0][S.charAt(i) - 'a'] = i + 1;
        for (int j = n - 2; j >= 0; --j) {
            for (int i = 0; i < 32; ++i) {
                dp[j + 1][i] = dp[j + 2][i];
            }
            dp[j + 1][S.charAt(j + 1) - 'a'] = j + 2;
        }
        int cnt = 0;
        for (String word : words) {
            int prv = 0;
            boolean ok = true;
            for (int j = 0; j < word.length(); ++j) {
                int nxt = dp[prv][word.charAt(j) - 'a'];
                if (nxt != -1) {
                    prv = nxt;
                } else ok = false;
            }
            if (ok) cnt++;
        }
        return cnt;
    }
    /*
    https://zxi.mytechroad.com/blog/string/leetcode-792-number-of-matching-subsequences/
     */
    private List<List<Integer>> pos;

    private boolean isMatch(String word) {
        int l = -1;
        for (char c : word.toCharArray()) {
            List<Integer> p = pos.get(c);
            int index = Collections.binarySearch(p, l + 1);
            if (index < 0) index = -index - 1;
            if (index >= p.size()) return false;
            l = p.get(index);
        }
        return true;
    }

    public int numMatchingSubseq2(String S, String[] words) {
        pos = new ArrayList<>();
        for (int i = 0; i < 128; ++i)
            pos.add(new ArrayList<Integer>());
        char[] s = S.toCharArray();
        for (int i = 0; i < s.length; ++i)
            pos.get(s[i]).add(i);
        int ans = 0;
        for (String word : words)
            if (isMatch(word)) ++ans;
        return ans;
    }
}
