#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

//-----------------------------------------

string decodeString(string s)
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

int main()
{
  //vector<int> input = {2, 0, 6, 6};
  auto ans = decodeString("222[bc]");
  cout << ans << endl;
}
