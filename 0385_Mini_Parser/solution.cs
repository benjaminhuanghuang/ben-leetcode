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

