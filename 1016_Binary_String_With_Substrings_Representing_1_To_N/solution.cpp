/*
1016. Binary String With Substrings Representing 1 To N

https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
*/

#include <string>

using namespace std;

/*
  Java solution can use String n = Integer.toBinaryString(i);
*/

/*
https://xingxingpark.com/Leetcode-1016-Binary-String-With-Substrings-Representing-1-To-N/
由于题目中给了S.length最大为1000，我们考虑11位二进制数（也就是1024 - 2047）总共有 > 1000个
然而长度为1000的字符串，取连续的11位数（即长度为11的子串），总共只能取1000 - 10 = 990种 < 1000 => 不可能包含所有11位binary，所以N最多也就是11位数，其上限为2^11 = 2048

只需要算 > N/2的数，因为如果一个数k的二进制是S的子串，那么k/2只不过少了一位，一定也是S的子串，没有必要再算。
*/
class Solution
{
public:
  bool queryString(string S, int N)
  {
    if (N >= 2048)
    {
      return false;
    }
    for (int i = N; i > N / 2; --i)
    {
      if (S.find(intToBinary(i)) == string::npos)
      {
        return false;
      }
    }
    return true;
  }

private:
  string intToBinary(int N)
  {
    string binary = "";
    while (N)
    {
      if (N & 1)
      {
        binary = "1" + binary;
      }
      else
      {
        binary = "0" + binary;
      }
      N /= 2;
    }
    return binary;
  }
};