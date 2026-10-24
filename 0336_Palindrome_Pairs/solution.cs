using System.Collections.Generic;

public class Solution336 {
    public IList<IList<int>> PalindromePairs(string[] words) {
        return null;
    }   

    bool IsPalindrome(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) 
                return false;
        }
        return true;
    }
}