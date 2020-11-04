/*
659. Split Array into Consecutive Subsequences

Level: Medium

https://leetcode.com/problems/split-array-into-consecutive-subsequences
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
  这就是所谓的扑克牌算法，必须全部弄成“顺子”。一个“顺子”至少3张连续的牌。方法是使用优先级队列，优先把当前的牌放入到更短的“顺子”里
*/

class Solution
{
public:
  bool isPossible(vector<int> &nums)
  {
    // int : min heap
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;

    int n = 0;
    for (int i : nums)
    {
      auto pre = m.find(i - 1);
      auto cur = m.find(i);
      if (pre == m.end())
      {
        if (cur == m.end())  // first time
        {
          priority_queue<int, vector<int>, greater<int>> q;
          q.push(1);
          m.insert({i, q});
        }
        else
        {
          m[i].push(1);
        }
      }
      else
      {
        int cnt = 1 + pre->second.top();
        pre->second.pop();
        if (pre->second.empty())
        {
          m.erase(pre);
        }

        if (cur == m.end())
        {
          priority_queue<int, vector<int>, greater<int>> q;
          q.push(cnt);
          m.insert({i, q});
        }
        else
        {
          m[i].push(cnt);
        }
      }
    }

    for (auto it : m)
    {
      if (!it.second.empty() & it.second.top() < 3)
        return false;
    }

    return true;
  }
};