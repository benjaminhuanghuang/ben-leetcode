package cn.huang.leetcode;

/*
    28	Implement strStr()
*/
public class LC_0028_ImplementstrStr {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null || haystack.length() < needle.length())
            return -1;
        if (needle.length() == 0 || haystack.equals(needle))
            return 0;


        // i <=
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            int j = 0;
            for (j = 0; j < needle.length(); j++) {
                if (haystack.charAt(i + j) != needle.charAt(j))
                    break;
            }
            if (j == needle.length())
                return i;
        }

        return -1;
    }

    public int strStr_better(String haystack, String needle) {
        if (haystack == null || needle == null || haystack.length() < needle.length())
            return -1;
        if (needle.length() == 0)
            return 0;
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substring(i, i + needle.length()).equals(needle))
                return i;
        }

        return -1;
    }
}