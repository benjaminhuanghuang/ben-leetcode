/*
709. To Lower Case
https://leetcode.com/problems/to-lower-case/
*/
#include <string>

using namespace std;

class Solution
{
public:
  string toLowerCase(string str)
  {
    // str is a copy
    for (char &c : str)
      if (c >= 'A' && c <= 'Z')
        c = c - 'A' + 'a';
    return str;
  }
};

class Solution
{
public:
  string toLowerCase(string str)
  {
    // str is a copy
    for (char &c : str)
      if (c >= 'A' && c <= 'Z')
        c ^= 32;  // 1 << 5
    return str;
  }
};