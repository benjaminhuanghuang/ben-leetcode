public class Solution389 {
    public char FindTheDifference(string s, string t) {
        char ans = (char)0;
        for (int i = 0; i < s.Length; i++) {
            ans ^= s[i];
        }
        for (int i = 0; i < t.Length; i++) {
        	ans ^= t[i];
        }
        return ans;
    }
}