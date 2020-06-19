/*
1370. Increasing Decreasing String

Level: Easy

https://leetcode.com/problems/increasing-decreasing-string
*/
#include <vector>
#include <string>
#include <unordered_map>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  string sortString_v2(string s)
  {
    int count[26] = {0};
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
      count[s[i] - 'a']++;
    }
    int flag = 0;
    while (flag < s.size())
    {
      for (int i = 0; i < 26; i++)
        if (count[i] > 0)
        {
          flag++;
          count[i]--;
          ans += 'a' + i;
        }
      for (int i = 25; i >= 0; i--)
        if (count[i] > 0)
        {
          flag++;
          count[i]--;
          ans += 'a' + i;
        }
    }
    return ans;
  }
  string sortString(string s)
  {
    unordered_map<char, int> record;
    for (auto &c : s)
      record[c]++;

    string res;
    while (res.size() < s.size())
    {
      add(res, record, true);
      add(res, record, false);
    }
    return res;
  }

private:
  void add(string &res, unordered_map<char, int> &record, bool pickSmall)
  {
    for (int i = 0; i < 26; ++i)
    {
      auto idx = pickSmall ? i : 25 - i;
      char c = 'a' + idx;
      if (record.count(c))
      {
        res += c;
        record[c]--;
        if (record[c] == 0)
          record.erase(c);
      }
    }
  }
};