package cn.huang.leetcode;

/*
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I


 */

/*

 */
public class LC_0006_ZigZagConversion {
    /*
    https://www.youtube.com/watch?v=8zXTAn7i5rU
    每一个row都用一个 string builder
     */
    public String convert1(String s, int numRows) {
        if (numRows == 1)
            return s;

        char[] charArr = s.toCharArray();
        int len = s.length();
        StringBuilder[] sbRows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            sbRows[i] = new StringBuilder();
        }

        int i = 0;
        while (i < len) {
            for (int row = 0; row < numRows && i < len; row++) {
                sbRows[row].append(charArr[i++]);      // vertically down
            }
            for (int row = numRows - 2; row >= 1 && i < len; row--) {
                sbRows[row].append(charArr[i++]);
            }
        }

        for (int r = 1; r < numRows; r++) {
            sbRows[0].append(sbRows[r]);
        }

        return sbRows[0].toString();
    }

    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;

        StringBuilder sb = new StringBuilder();

        // step
        int step = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            //first & last rows
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.length(); j = j + step) {
                    sb.append(s.charAt(j));
                }
                //middle rows
            } else {
                int j = i;
                boolean flag = true;
                int step1 = 2 * (numRows - 1 - i);
                int step2 = step - step1;

                while (j < s.length()) {
                    sb.append(s.charAt(j));
                    if (flag)
                        j = j + step1;
                    else
                        j = j + step2;
                    flag = !flag;
                }
            }
        }

        return sb.toString();
    }
}
