/*
394. Decode String

*/
#include <string>
#include <stack>

using namespace std;

/*
Solution: recursion

Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution
{
public:
  string decodeString(string s)
  {
    if (s.empty())
      return "";
    string ans;
    int i = 0;
    int n = s.length();
    int c = 0;
    while (isdigit(s[i]) && i < n)
      c = c * 10 + (s[i++] - '0');

    int j = i;
    if (i < n && s[i] == '[')
    {
      int open = 1;
      while (++j < n && open)
      {
        if (s[j] == '[')
          ++open;
        if (s[j] == ']')
          --open;
      }
    }
    else
    {
      while (j < n && isalpha(s[j]))
        ++j;
    }

    // "def2[ac]" => "def" + decodeString("2[ac]")
    //  |  |
    //  i  j
    if (i == 0)
      return s.substr(0, j) + decodeString(s.substr(j));

    // "3[a2[c]]ef", ss = decodeString("a2[c]") = "acc"
    //   |      |
    //   i      j
    string ss = decodeString(s.substr(i + 1, j - i - 2));
    while (c--)
      ans += ss;
    // "3[a2[c]]ef", ans = "abcabcabc", ans += decodeString("ef")
    ans += decodeString(s.substr(j));
    return ans;
  }

  string decodeString_stack(string s)
  {
    if (s.empty())
      return "";

    string ans;
    // 记录'['之前的数字
    stack<int> countStack;
    // 记录'['之前的运算结果
    stack<string> resStack;
    int i = 0;
    int curNum = 0;
    while (i < s.length())
    {
      char ch = s[i];
      if (isdigit(ch))
      {
        while (isdigit(s[i]))
          curNum = 10 * curNum + (s[i++] - '0');
      }
      else if (ch == '[')
      {
        // backup ans ans count and work on []
        resStack.push(ans);
        ans = ""; // 注意
        // 此push可以放在上面的while循环中
        countStack.push(curNum);
        curNum = 0; // 注意
        i++;
      }
      else if (ch == ']')
      {
        // 取出计算结果，和数字
        string temp = resStack.top();
        resStack.pop();

        int repeatTimes = countStack.top();
        countStack.pop();

        for (int j = 0; j < repeatTimes; j++)
        {
          temp.append(ans);
        }
        ans = temp;
        i++;
      }
      else
      {
        // current char is letter
        ans += s[i];
        i++;
      }
    }
    return ans;
  }
};