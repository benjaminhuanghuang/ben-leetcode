/*
541. Reverse String II

https://leetcode.com/problems/reverse-string-ii

题目大意：把字符串分成块，每块长度2k，单独反转每一块的前k的字符。
*/
#include <string>
using namespace std;

/*

*/
class Solution
{
public:
  string reverseStr(string s, int k)
  {
    const int n = s.length();
    for (int i = 0; i <= n / k; i += 2)
      std::reverse(s.begin() + i * k, s.begin() + min(n, (i + 1) * k));   // min() is important
    return s;
  }
};