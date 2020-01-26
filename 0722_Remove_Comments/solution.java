package cn.huang.leetcode;
/*
722. Remove Comments
Given a C++ program, remove comments from it. The program source is an array where source[i] is the i-th line of the source code. This represents the result of splitting the original source code string by the newline character \n.

In C++, there are two types of comments, line comments, and block comments.

The string // denotes a line comment, which represents that it and rest of the characters to the right of it in the same line should be ignored.
 */


import java.util.ArrayList;
import java.util.List;

public class LC_0722_RemoveComments {
    public List<String> removeComments(String[] source) {
        List<String> ret = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int row = 0, col = 0;
        boolean comment = false;
        while (row < source.length) { //comment如果为true，表明当前行前面有/*
            if (comment) {
                //找到代码中*/的位置，并将该位置放在index变量中
                int index = source[row].indexOf("*/", col);
                //如果index = -1说明当前行没有*/，则将行数row+1，将下一行的起始下标置0
                if (index == -1) {
                    row++;
                    col = 0; //如果index的值不为-1，则说明当前行找到了*/ 则将代码行的有效代码下标置为index+2。及那个comment置为false
                } else {
                    comment = false;
                    col = index + 2;
                }
            } else { //获取当前行/*的下标
                int index1 = source[row].indexOf("/*", col);
                //获取当前行//的下标
                int index2 = source[row].indexOf("//", col);
                //如果index1 = -1说明，当前行没有/*，则正行都是有效代码，将其长度放在index1中
                if (index1 == -1)
                    index1 = source[row].length(); //如果index2 = -1说明，当前行没有//，则正行都是有效代码，将其长度放在index2中
                if (index2 == -1)
                    index2 = source[row].length(); //把非评论部分放入
                for (int i = col; i < Math.min(index1, index2); i++) {
                    sb.append(source[row].charAt(i));
                } //这里比较//和/*第一次出现的位置，如果//在/*前面出现，就说明该行是被//注释的，否则是被/*注释的
                if (index2 <= index1) {
                    if (sb.length() > 0) {
                        ret.add(new String(sb));
                        sb.setLength(0);
                    }
                    row++;
                    col = 0;
                } else {
                    comment = true;
                    col = index1 + 2;
                }
            }
        }
        return ret;
    }
}
