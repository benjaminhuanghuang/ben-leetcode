/*
1023. Camelcase Matching [Medium]

https://leetcode.com/problems/camelcase-matching/
*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern)
  {
    vector<bool> ans;
    for (const string &q : queries)
      ans.push_back(match(q, pattern));
    return ans;
  }

private:
  bool match(const string &query, const string &pattern)
  {
    int j = 0; // index for pattern
    for (int i = 0; i < query.length(); ++i)
    {
      if (j < pattern.length() && query[i] == pattern[j])
        ++j;
      else if(query[i] < 'a' || query[i]>'z')  // query[i] is not lower case
      {
        return false;
      }
    }
    return j == pattern.length();
  }
};