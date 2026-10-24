/*
58. Length of Last Word

https://leetcode.com/problems/length-of-last-word/
*/
#include <string>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    if (s.empty())
      return 0;

    int len = s.size();
    int count = 0;
    for (int i = len - 1; i >= 0; i--)
    {
      if (s[i] != ' ')  // count letters
        count++;
      if (s[i] == ' ' && count != 0)  // skip the spaces at the end
        return count;
    }
    return count;
  }
};