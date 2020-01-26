package cn.huang.leetcode;

/*
443. String Compression
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Follow up:
Could you solve it using only O(1) extra space?

Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.

Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.

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
