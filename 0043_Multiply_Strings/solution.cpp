/*
43. Multiply Strings

https://leetcode.com/problems/multiply-strings/
*/
#include <string>

using namespace std;
/*
  https://www.cnblogs.com/grandyang/p/4395356.html

      8 9  <- num2
      7 6  <- num1
  -------
      5 4
    4 8
    6 3
  5 6
  -------
  6 7 6 4
  num1 和 num2 中任意位置的两个数字相乘，得到的两位数在最终结果中的位置是确定的，
  比如 num1 中位置为i的数字乘以 num2 中位置为j的数字，那么得到的两位数字的位置为 i+j 和 i+j+1，
  注意方向：两个数字从右向左，result从左向右
  从个位数乘起, 乘得的结果放在res的[i+j][i+j+1]上 [i+j+1]是低位
*/
class Solution
{
public:
  string multiply(string num1, string num2)
  {
    const int l1 = num1.length();
    const int l2 = num2.length();
    string ans(l1 + l2, '0');
    for (int i = l1 - 1; i >= 0; --i)
      for (int j = l2 - 1; j >= 0; --j)
      {
        int sum = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
        ans[i + j + 1] = (sum % 10) + '0';
        ans[i + j] += sum / 10;
      }
    for (int i = 0; i < ans.length(); ++i)
      if (ans[i] != '0' || i == ans.length() - 1)
        return ans.substr(i);
    return "";
  }
};