package cn.huang.leetcode;

import java.util.List;
import java.util.Stack;

/*
385. Mini Parser

Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

    String is non-empty.
    String does not contain white spaces.
    String contains only digits 0-9, [, - ,, ].

Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.

Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.

 */
public class LC_0385_MiniParser {
    /**
     * // This is the interface that allows for creating nested lists.
     * // You should not implement it, or speculate about its implementation
     */
    public class NestedInteger {
        // Constructor initializes an empty nested list.
        public NestedInteger() {
        }

        // Constructor initializes a single integer.
        public NestedInteger(int value) {
        }

        // @return true if this NestedInteger holds a single integer, rather than a nested list.
        public boolean isInteger() {
            return false;
        }

        // @return the single integer that this NestedInteger holds, if it holds a single integer
        // Return null if this NestedInteger holds a nested list
        public Integer getInteger() {
            return 0;
        }

        // Set this NestedInteger to hold a single integer.
        public void setInteger(int value) {
        }

        // Set this NestedInteger to hold a nested list and adds a nested integer to it.
        public void add(NestedInteger ni) {
        }

        // @return the nested list that this NestedInteger holds, if it holds a nested list
        // Return null if this NestedInteger holds a single integer
        public List<NestedInteger> getList() {
            return null;
        }
    }

    public NestedInteger deserialize(String s) {
        Stack<NestedInteger> stack = new Stack<>();
        String tokenNum = "";

        for (char c : s.toCharArray()) {
            if (c == '[') {
                stack.push(new NestedInteger());
            } else if (c == ']') {
                if (tokenNum.length() > 0) {
                    stack.peek().add(new NestedInteger(Integer.parseInt(tokenNum)));
                }
                NestedInteger ni = stack.pop();//本层list结束
                tokenNum = "";
                if (stack.size() > 0) {//栈内有更高层次的list
                    stack.peek().add(ni);
                } else {//栈为空，遍历到字符串结尾
                    return ni;
                }
            } else if (c == ',') {
                if (tokenNum.length() > 0) //将数字加入到本层list中
                    stack.peek().add(new NestedInteger(Integer.parseInt(tokenNum)));
                tokenNum = "";
            } else //number
            {
                tokenNum += c;
            }
        }
        if (tokenNum.length() > 0)//特殊case: 如果字符串只包含数字的情况
            return new NestedInteger(Integer.parseInt(tokenNum));
        return null;
    }
}
