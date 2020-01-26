/*
521. Longest Uncommon Subsequence I 

https://leetcode.com/problems/longest-uncommon-subsequence-i/
*/

#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/string/leetcode-521-longest-uncommon-subsequence-i/

If two strings are the same, then the longest uncommon sequence does not exist, return -1.
Otherwise, the longer string is always a uncommon sequence of the shorter one.
e.g. aaab vs aaa, return 4

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
public:
  int findLUSlength(string a, string b)
  {
    return a == b ? -1 : max(a.length(), b.length());
  }
};