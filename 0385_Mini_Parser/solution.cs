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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * interface NestedInteger {
 *
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool IsInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     int GetInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void SetInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void Add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     IList<NestedInteger> GetList();
 * }
 */
using System;
using System.Collections.Generic;

public class Solution385 {
    public class NestedInteger
    {
        public NestedInteger(){}
 
      // Constructor initializes a single integer.
      public NestedInteger(int value){}
 
      // @return true if this NestedInteger holds a single integer, rather than a nested list.
      bool IsInteger(){return false;}
 
      // @return the single integer that this NestedInteger holds, if it holds a single integer
      // Return null if this NestedInteger holds a nested list
      int GetInteger(){return 0;}
 
      // Set this NestedInteger to hold a single integer.
      public void SetInteger(int value){}
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      public void Add(NestedInteger ni){}
 
      // @return the nested list that this NestedInteger holds, if it holds a nested list
      // Return null if this NestedInteger holds a single integer
      IList<NestedInteger> GetList(){return null;}
    }
    public NestedInteger Deserialize(string s) {
        var stack = new Stack<NestedInteger>();
        string tokenNum="";
        foreach(char c in s){
            if (c == '[')
            {
                stack.Push(new NestedInteger());
            }
            else if (c == ']')
            {
                if (tokenNum.Length >0)
                {
                    stack.Peek().Add(new NestedInteger(Int32.Parse(tokenNum)));
                }
                NestedInteger ni = stack.Pop();//本层list结束
				tokenNum = "";
				if (stack.Count>0) {//栈内有更高层次的list
					stack.Peek().Add(ni);
				} 
                else {//栈为空，遍历到字符串结尾
					return ni;
				}
            }
            else if( c==',')
            {
                if (tokenNum.Length > 0) //将数字加入到本层list中
					stack.Peek().Add(new NestedInteger(Int32.Parse(tokenNum)));
				tokenNum = "";
		    }
            else //number
            {
                tokenNum += c;
            }
        }
        if (tokenNum.Length > 0)//特殊case: 如果字符串只包含数字的情况
			return new NestedInteger(Int32.Parse(tokenNum));
        return null;
    }
}

