/*
1047. Remove All Adjacent Duplicates In String

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

#include <string>
#include <deque>

using namespace std;

class Solution
{
public:
  string removeDuplicates(string S)
  {
    deque<char> s;
    for (char c : S)
    {
      if (!s.empty() && s.back() == c)
        s.pop_back();
      else
        s.push_back(c);
    }
    return {begin(s), end(s)};
  }
};