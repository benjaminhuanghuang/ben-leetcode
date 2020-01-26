package cn.huang.leetcode;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Stack;

/*
388. Longest Absolute File Path

Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext

The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system.
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its
length 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:

    The name of a file contains at least a . and an extension.
    The name of a directory or sub-directory will not contain a ..

Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 */
public class LC_0388_LongestAbsoluteFilePath {
    /*
    http://bookshadow.com/weblog/2016/08/21/leetcode-longest-absolute-file-path/
     */
    public int lengthLongestPath(String input) {
        int maxlen = 0;
        // hold length of each depth in one line
        HashMap<Integer, Integer> pathlen = new HashMap<Integer, Integer>();
        pathlen.put(0, 0);
        for (String line : input.split("\n")) {
            //  Remove all '\t' from line, python: name = line.lstrip('\t')
            String name = line.replace("\t", "");
            int depth = line.length() - name.length();  // 有几个\t 说明有几级目录
            if (name.indexOf('.') >= 0) // is a file
                maxlen = Math.max(maxlen, pathlen.get(depth) + name.length());
            else
                pathlen.put((depth + 1), pathlen.get(depth) + name.length() + 1);
        }
        return maxlen;
    }

    /*
    https://www.jianshu.com/p/1b1e2021b5e9
    每个name 前面的 \t 个数不相同，可以拿这个来区分不同level的文件。
    比如：
    dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext
    dir: 0
    subdir1: 1
    subdir2: 1
    file.ext: 2
    数字表示前面 \t 的个数，正好也可以作为层数。
    于是做一个栈。如果当前需要插进去的元素，他的level <= 栈顶元素的level，那么把栈顶的弹出去，直到满足条件为止。
    然后在整个过程中，记录下栈里面所有字母的个数。
    记住，栈里面存放的是整个路径，但是没有加上 ''
    所以，每次插入的时候，我们给counter加时，都手动加个1，表示
    当然，  dir 是不需要 \ 的，所以，在最后返回结果的时候，如果max > 0, 那么 max - 1去掉这个不需要加 '' 的重复。
     */
    public int lengthLongestPath2(String input) {
        if (input == null || input.length() == 0) {
            return 0;
        }

        String[] parts = input.split("\n");
        if (parts == null || parts.length == 0) {
            return 0;
        }

        Stack<String> st = new Stack<String>();
        int max = 0;
        int counter = 0;
        for (int i = 0; i < parts.length; i++) {
            String s = parts[i];
            int level = getLevel(s);
            while (!st.isEmpty() && level <= st.size() - 1) {
                String out = st.pop();
                counter -= (out.length() + 1);
            }
            String removeT = s.replaceAll("\t", "");
            st.push(removeT);
            counter += removeT.length() + 1;
            if (removeT.indexOf(".") != -1) {
                max = Math.max(max, counter);
            }
        }

        return max == 0 ? 0 : max - 1;
    }

    private int getLevel(String s) {
        String temp = s.replaceAll("\t", "");
        return s.length() - temp.length();
    }

    public int lengthLongestPath3(String input) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0); // "dummy" length
        int maxLen = 0;
        for (String s : input.split("\n")) {
            int lev = s.lastIndexOf("\t") + 1; // number of "\t"
            while (lev + 1 < stack.size())
                stack.pop(); // find parent
            int len = stack.peek() + s.length() - lev + 1; // remove "/t", add"/"
            stack.push(len);
            // check if it is file
            if (s.contains("."))
                maxLen = Math.max(maxLen, len - 1);
        }
        return maxLen;
    }
}
