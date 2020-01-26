package cn.huang.leetcode;

/*
    434. Number of Segments in a String
    Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

    Please note that the string does not contain any non-printable characters.

    Example:

    Input: "Hello, my name is John"
    Output: 5
 */
public class LC_0434_NumberofSegmentsinaString {
    public int countSegments(String s) {
        if (s == null)
            return 0;
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            {
                if (s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')) {
                    ++count;
                }
            }
        }
        return count;
    }
}

