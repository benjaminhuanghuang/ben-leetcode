package cn.huang.leetcode;

/*
    806. Number of Lines To Write String
    how many lines have at least one character from S, and what is the width used by the last such line?
    Return your answer as an integer list of length 2.
 */
public class LC_0806_NumberofLinesToWriteString {

    public int[] numberOfLines(int[] widths, String S) {
        int[] result = {0, 0};
        char[] chars = S.toCharArray();
        int space = 0;
        for (int i = 0; i < S.length(); i++) {
            if (100 - space >= widths[chars[i] - 'a']) {
                space += widths[chars[i] - 'a'];
            } else {
                // add new line
                result[0] += 1;
                space = widths[chars[i] - 'a'];
            }

        }
        result[0]++;
        result[1] = space;
        return result;
    }
}
