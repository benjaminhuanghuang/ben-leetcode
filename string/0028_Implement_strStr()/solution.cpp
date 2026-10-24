/*
28. Implement strStr()
https://leetcode.com/problems/implement-strstr/
*/
#include <string>

using namespace std;
/*
Time complexity: O(mn)

Space complexity: O(1)
*/
class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    const int l1 = haystack.length();
    const int l2 = needle.length();
    for (int i = 0; i <= l1 - l2; ++i)
    {
      int j = 0;
      while (j < l2 && haystack[i + j] == needle[j])
        ++j;
      if (j == l2)
        return i;
    }
    return -1;
  }
};