/*
1560. Most Visited Sector in  a Circular Track

Level: Easy

https://leetcode.com/problems/most-visited-sector-in-a-circular-track
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.acwing.com/file_system/file/content/whole/index/content/1188844/
  如果 start 小于等于 end，则答案就是区间 [start, ened]。否则，答案就是区间 [1, end] 并上 [start, n]。
*/
class Solution
{
public:
  vector<int> mostVisited(int n, vector<int> &rounds)
  {
    vector<int> ans;
    int start = rounds[0];
    int end = rounds[rounds.size() - 1];

    if (start > end)
    {
      for (int i = 1; i <= end; i++)
      {
        ans.push_back(i);
      }
      for (int i = start; i <= n; i++)
      {
        ans.push_back(i);
      }
    }
    else
    {
      for (int i = start; i <= end; i++)
      {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

/*
  https://zxi.mytechroad.com/blog/simulation/leetcode-1560-most-visited-sector-in-a-circular-track/
*/
class Solution
{
public:
  vector<int> mostVisited(int n, vector<int> &rounds)
  {
    vector<int> counts(n);
    counts[rounds[0] - 1] = 1;
    for (int i = 1; i < rounds.size(); ++i)
      for (int s = rounds[i - 1];; ++s)
      {
        ++counts[s %= n];
        if (s == rounds[i] - 1)
          break;
      }
    const int max_count = *max_element(begin(counts), end(counts));
    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (counts[i] == max_count)
        ans.push_back(i + 1);
    return ans;
  }
};