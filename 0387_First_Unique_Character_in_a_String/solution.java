package cn.huang.leetcode;

/*
387. First Unique Character in a String

 */
public class LC_0387_FirstUniqueCharacterinaString {
    public int firstUniqChar(String s) {
        char[] array = s.toCharArray();
        int[] a = new int[26];

        for (int i = 0; i < s.length(); i++)
            a[array[i] - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            if (a[array[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
}
