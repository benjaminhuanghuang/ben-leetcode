package cn.huang.leetcode;

/*
    171. Excel Sheet Column Number
 */
public class LC_0171_ExcelSheetColumnNumber {
    public int titleToNumber(String s) {
        if (s == null || s.length() == 0)
            return -1;

        char[] chars = s.toCharArray();
        int n = 0;
        for (int i = 0; i < chars.length ; i++) {
            int charVal = chars[i] - 'A' + 1;
            n = n * 26 + charVal;
        }
        return n;
    }
}
