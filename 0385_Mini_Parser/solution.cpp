/*
385. Mini Parser

https://leetcode.com/problems/mini-parser/


similar problems:
  Nested List Weight Sum II
  Flatten Nested List Iterator
  Nested List Weight Sum
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger
{
public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class Solution
{
public:
  NestedInteger deserialize(string s)
  {
    if (s.empty())
      return NestedInteger();
    if (s[0] != '[')
      return NestedInteger(stoi(s));
    if (s.size() <= 2)
      return NestedInteger();

    NestedInteger res;
    int start = 1, cnt = 0;
    for (int i = 1; i < s.size(); ++i)
    {
      if (cnt == 0 && (s[i] == ',' || i == s.size() - 1))
      {
        res.add(deserialize(s.substr(start, i - start)));
        start = i + 1;
      }
      else if (s[i] == '[')
        ++cnt;
      else if (s[i] == ']')
        --cnt;
    }
    return res;
  }
};
/*
  Stack
*/
class Solution
{
public:
  NestedInteger deserialize(string s)
  {
    if (s.empty())
      return NestedInteger();
    stack<NestedInteger> st;
    string tokenNum;

    for (char c : s)
    {
      if (c == '[')
      {
        st.push(NestedInteger());
      }
      else if (c == ']')
      {
        if (!tokenNum.empty())
        {
          st.top().add(NestedInteger(stoi(tokenNum)));
        }
        NestedInteger ni = st.top(); //本层list结束
        st.pop();
        tokenNum = "";
        if (!st.empty())
        { //栈内有更高层次的list
          st.top().add(ni);
        }
        else
        { //栈为空，遍历到字符串结尾
          return ni;
        }
      }
      else if (c == ',')
      {
        if (!tokenNum.empty()) //将数字加入到本层list中
          st.top().add(NestedInteger(stoi(tokenNum)));
        tokenNum = "";
      }
      else //number
      {
        tokenNum += c;
      }
    }
    if (!tokenNum.empty()) //特殊case: 如果字符串只包含数字的情况
      return NestedInteger(stoi(tokenNum));
    return NestedInteger();
  }
};