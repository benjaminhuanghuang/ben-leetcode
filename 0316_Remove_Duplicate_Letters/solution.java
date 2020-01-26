package cn.huang.leetcode;

import java.util.Stack;

/*
316. Remove Duplicate Letters

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and
only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"

Example 2:

Input: "cbacdcbc"
Output: "acdb"

 */

/*
输入一个字符串，字母来自a-z，然后去除里面重复的字符，使得每个字母只能保留一个，且最后的字符串又是字母序最小的。
用最原始的分析思路，用例子的bcabc来说明。

    依次扫描字符。
    发现是b，放到结果里。 > b
    发现是c，回头看看已有的b，虽然后面也有b，但是b很小，没必要用后面的。 >bc
    继续扫描a，发现前面的bc都比a大，而且后面还有bc，那么bc清理掉。放入a。简单理解则是：后面有更优的（字母序小） >a
    继续扫描b，发现里面还没放入,而且前面的都小；>ab
    继续扫描c，发现没有，而且前面的都是小的，直接放入; >abc
    结束。
 */
public class LC_0316_RemoveDuplicateLetters {
    public String removeDuplicateLetters(String s) {
        //统计每个字符出现的次数
        int[] count = new int[26];
        char cs[] = s.toCharArray();
        for (char c : cs) {
            count[c - 'a']++;
        }
        //每个字符是否使用，由于只保留一个，所以这地方最多需要26个。
        boolean visited[] = new boolean[26]; //结果集

        Stack<Character> result = new Stack<Character>();
        for (char c : cs) {
            count[c - 'a']--; //结果集里已经有了，不需要再放进来了。
            if (visited[c - 'a'])
                continue;
            //优化步骤
            while (!result.isEmpty() && count[result.peek() - 'a'] > 0 && c < result.peek()) {
                //后面有更好的，则删除，设置为没有用过。
                visited[result.peek() - 'a'] = false;
                result.pop();
            } //更新状态
            result.push(c);
            visited[c - 'a'] = true;
        }
        s = ""; //正序，先入的先出！
        for (char c : result)
            s += c;
        return s;
    }
}
