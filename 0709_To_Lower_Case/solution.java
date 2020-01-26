package cn.huang.leetcode;

public class LC_0709_ToLowCase {
    public String toLowerCase(String str) {
        if (str == null)
            return null;
        if (str.length() == 0)
            return "";

        char[] chars = new char[str.length()];

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c >= 'A' && c <= 'Z')
                chars[i] = (char) ('a' + c - 'A');
            else
                chars[i] = c;
        }
        return String.valueOf(chars);
    }
}
