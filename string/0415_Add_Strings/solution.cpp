/*
415. Add Strings

https://leetcode.com/problems/add-strings/
*/
#include <string>
#include <vector>

using namespace std;

/*
  Faster and no extral space
*/
class Solution
{
public:
  string addStrings(string num1, string num2)
  {
    if (num1.length() < num2.length())
      swap(num1, num2);
      
    num1 = "0" + num1;
    int l1 = num1.length();
    int l2 = num2.length();
    for (int i = 0; i < l1 - 1; ++i)
    {
      if (i < l2)
        num1[l1 - i - 1] += (num2[l2 - i - 1] - '0');
      if (num1[l1 - i - 1] > '9')
      {
        num1[l1 - i - 1] -= 10;
        ++num1[l1 - i - 2];
      }
    }
    return (num1[0] != '0') ? num1 : num1.substr(1);
  }
};


class Solution_easy
{
public:
  string addStrings(string num1, string num2)
  {
     int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0) {
            if (i >= 0)
                carry += num1[i--] - '0';
            if (j >= 0)
                carry += num2[j--] - '0';
            res = to_string(carry % 10) + res;
            carry /= 10;
        }
        return carry != 0 ? "1" + res : res;
  }
};