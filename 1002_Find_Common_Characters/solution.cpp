/*
1002. Find Common Characters

https://leetcode.com/problems/find-common-characters/
*/

#include <vector>
#include <string>

using namespace std;
/*
Min count for each character

Time complexity: O(n*l)
Space complexity: O(1)
*/
class Solution
{
public:
  vector<string> commonChars(vector<string> &A)
  {
    vector<int> min_count(26, INT_MAX);
    for (const string &a : A)
    {
      vector<int> count(26, 0);
      for (const char ch : a)
        ++count[ch - 'a'];
      for (int i = 0; i < 26; ++i)
        min_count[i] = min(min_count[i], count[i]);
    }
    vector<string> ans;
    for (int i = 0; i < 26; ++i)
    {
      if (min_count[i] == INT_MAX)
        continue;
      for (int j = 0; j < min_count[i]; ++j)
        ans.push_back(string(1, 'a' + i));
    }
    return ans;
  }
};