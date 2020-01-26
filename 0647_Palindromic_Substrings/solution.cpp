/*
  647. Palindromic Substrings

  https://leetcode.com/problems/palindromic-substrings/
*/

#include <string>

using namespace std;
/*
  取一个中点，向两边延伸
  Time complexity: O(n^2)
  Space complexity: O(1)
*/
class Solution
{
public:
  int countSubstrings(string s)
  {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
      ans += count(s, i, i);     // odd length
      ans += count(s, i, i + 1); // even length
    }
    return ans;
  }

private:
  int count(const string &s, int l, int r)
  {
    int ans = 0;
    while (l >= 0 & r < s.length() && s[l--] == s[r++])
      ++ans;
    return ans;
  }
};