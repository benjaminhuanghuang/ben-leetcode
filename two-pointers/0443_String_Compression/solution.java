package cn.huang.leetcode;

/*

 */
public class LC_0443_StringCompression {
    //两个指针即可完成，一个指针做遍历，另一个做结果的遍历
    public int compress(char[] chars) {

        if (chars == null || chars.length < 1)
            return 0;
        int index_letter = 0;
        int index_result = 0;
        for (int i = 0; i < chars.length; i++) {
            if (i == chars.length - 1 || chars[i] != chars[i + 1]) {
                chars[index_result] = chars[index_letter];   // fill the letter to result
                index_result++;

                if (index_letter < i) {
                    // the moves
                    for (char a : ("" + (i - index_letter + 1)).toCharArray())
                        chars[index_result++] = a;
                }
                index_letter = i + 1;
            }
        }
        return index_result;
    }
}
