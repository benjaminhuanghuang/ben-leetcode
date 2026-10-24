package cn.huang.leetcode;

import java.util.Stack;

/*
394. Decode String


 Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

 */
public class LC_0394_DecodeString {
    /*
    https://blog.csdn.net/mine_song/article/details/71036245
     */
    public String decodeString(String s) {
        String res = "";
        // 记录'['之前的数字
        Stack<Integer> countStack = new Stack<>();
        // 记录'['之前的运算结果
        Stack<String> resStack = new Stack<>();
        int i = 0;
        int curNum = 0;
        while (i < s.length()) {
            char ch = s.charAt(i);
            if (Character.isDigit(ch)) {
                while (Character.isDigit(s.charAt(i)))
                    curNum = 10 * curNum + (s.charAt(i++) - '0');
            } else if (ch == '[') {
                resStack.push(res);
                res = "";// 注意
                // 此push可以放在上面的while循环中
                countStack.push(curNum);
                curNum = 0;// 注意
                i++;
            } else if (ch == ']') {
                // 取出计算结果，和数字
                StringBuilder temp = new StringBuilder(resStack.pop());

                int repeatTimes = countStack.pop();
                for (int j = 0; j < repeatTimes; j++) {
                    temp.append(res);
                }
                res = temp.toString();
                i++;
            } else {
                // 字母
                res += s.charAt(i++);
            }
        }
        return res;
    }
}
