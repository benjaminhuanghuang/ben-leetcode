/*
13. Roman to Integer

https://leetcode.com/problems/roman-to-integer/
*/

#include <string>
#include <unordered_map>

using namespace std;

/*
If the value of current letter is greater than the previous one, deduct twice of the previous value.

e.g. IX, 1 + 10 – 2 * 1 = 9 instead of 1 + 10 = 11

Time complexity: O(n)

Space complexity: O(1)
*/
class Solution
{
public:
  int romanToInt(string s)
  {
    unordered_map<char, int> m{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
      ans += m[s[i]];
      if (i > 0 && m[s[i]] > m[s[i - 1]])
        ans -= 2 * m[s[i - 1]];
    }
    return ans;
  }
};