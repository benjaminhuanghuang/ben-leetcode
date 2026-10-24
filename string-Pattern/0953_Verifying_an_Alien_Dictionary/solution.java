package cn.huang.leetcode;

/*
953. Verifying an Alien Dictionary
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order.
The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if
the given words are sorted lexicographicaly in this alien language.

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

 */
public class LC_0953_VerifyinganAlienDictionary {
    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < words.length - 1; i++) {
            if (!orderd(words[i], words[i + 1], order)) {
                return false;
            }
        }
        return true;
    }

    private boolean orderd(String word1, String word2, String order) {
        int len1 = word1.length();
        int len2 = word2.length();
        int i1 = 0;
        int i2 = 0;
        while (i1 < len1 || i2 < len2) {
            char c1 = i1 < len1 ? word1.charAt(i1) : 'A';
            char c2 = i2 < len2 ? word2.charAt(i2) : 'A';
            if (order.indexOf(c1) < order.indexOf(c2))
                break;
            else if (order.indexOf(c1) > order.indexOf(c2))
                return false;
            if (i1 >= len1 || i2 >= len2)
                break;
            i1++;
            i2++;
        }

        return true;
    }
}
