/*
761. Special Binary String

https://leetcode.com/problems/special-binary-string/
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
Special binary string 的定义
1. 字符串0和1出现的次数相等
2. 非常关键，字符串开始一定是以1开头，且前缀1出现的次数至少与0出现的次数相等。比如”11100100”是special binary string，
因为1出现的次数始终大于等于0。
 
 https://blog.csdn.net/magicbean2/article/details/79590505
 */
class Solution
{
public:
  string makeLargestSpecial(string S)
  {
    int count = 0, i = 0;
    vector<string> res;
    for (int j = 0; j < S.size(); ++j)
    {
      if (S[j] == '1')
      {
        ++count;
      }
      else
      {
        --count;
      }
      if (count == 0)
      {
        res.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
        i = j + 1;
      }
    }
    sort(res.begin(), res.end(), greater<string>());
    string ans = "";
    for (int i = 0; i < res.size(); ++i)
    {
      ans += res[i];
    }
    return ans;
  }
};