/*
831. Masking Personal Information

https://leetcode.com/problems/masking-personal-information/
*/
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution
{
private:
  string prefix[4] = {"", "+*-", "+**-", "+***-"};

public:
  string maskPII(string S)
  {
    int at = S.find('@'); // 用来判断是不是邮箱
    if (at != string::npos)
    {
      // process email "LeetCode@LeetCode.com" to "l*****e@leetcode.com"
      transform(S.begin(), S.end(), S.begin(), ::tolower);
      S.replace(1, at - 2, "*****");
    }
    else
    {
      // process phone number
      S = regex_replace(S, regex("[^0-9]"), ""); //  过滤非数字
      int n = S.length();
      S = prefix[n - 10] + "***-***-" + S.substr(n - 4);
    }
    return S;
  }
};
