/*
451. Sort Characters By Frequency

Level: Medium

https://leetcode.com/problems/sort-characters-by-frequency
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <numeric>
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
  string frequencySort(string s)
  {
    map<char, int> f;
    for (char c : s)
      ++f[c];
    sort(s.begin(), s.end(), [&f](char a, char b) {
      return f[a] > f[b] || (f[a] == f[b] && a > b);
    });
    return s;
  }
};

class Solution
{
public:
  string frequencySort(string s)
  {
    vector<int> f(128, 0);
    for (char c : s)
      ++f[c];
    vector<pair<int, char>> v;
    for (int i = 0; i < 128; ++i)
    {
      if (f[i] > 0)
        v.emplace_back(f[i], i);
    }
    sort(v.rbegin(), v.rend());
    string ans;
    for (const auto &kv : v)
    {
      ans.append(kv.first, kv.second);
    }
    return ans;
  }
};