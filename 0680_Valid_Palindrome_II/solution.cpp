/*
680. Valid Palindrome II

https://leetcode.com/problems/valid-palindrome-ii/
*/
#include <string>

using namespace std;
/*
  O(N)
*/
class Solution
{
public:
  bool validPalindrome(const string &s)
  {
    int l = -1;
    int r = s.length();
    while (++l < --r)
      if (s[l] != s[r]) // delete l or r
        return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
    return true;
  }

private:
  bool isPalindrome(const string &s, int l, int r)
  {
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};