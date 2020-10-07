
/*
49. Group Anagrams

https://leetcode.com/problems/group-anagrams/
*/
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    for (string str : strs)
    {
      string t = str;
      sort(t.begin(), t.end());  // key = sorted(str)
      m[t].push_back(str);
    }
    for (auto a : m)
    {
      res.push_back(a.second);  // push the vector<string> to res
    }
    return res;
  }
};