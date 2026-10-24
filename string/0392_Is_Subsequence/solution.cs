public class Solution392 {
    public bool IsSubsequence(string s, string t) {
        if (s.Length == 0) return true;
        int i = 0, j = 0;
        while (i < s.Length && j < t.Length) {
            if (s[i] == t[j]) {
                ++i; ++j;
            } else {
                ++j;
            }
        }
        return i == s.Length;
    }
}