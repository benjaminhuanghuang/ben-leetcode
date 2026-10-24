public class Solution383 {
    // Much better than using Dictionary.
    public bool CanConstruct(string ransomNote, string magazine) {
        int[] cnt = new int[26];
        for (int i = 0; i < magazine.Length; i++) {
            cnt[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.Length; i++) {
            if(cnt[ransomNote[i]-'a'] -- < 0) {
                return false;
            }
        }
        return true;
    }
}