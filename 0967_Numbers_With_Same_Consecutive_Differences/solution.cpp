/*
967. Numbers With Same Consecutive Differences

Level: Medium

https://leetcode.com/problems/numbers-with-same-consecutive-differences
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
*/

class Solution
{
public:
  vector<int> numsSameConsecDiff(int N, int K)
  {
    vector<int> ans;
    if (N == 1)
      ans.push_back(0);
    for (int i = 1; i <= 9; ++i)
      dfs(N - 1, K, i, ans);
    return ans;
  }

private:
  void dfs(int N, int K, int cur, vector<int> &ans)
  {
    if (N == 0)
    {
      ans.push_back(cur);
      return;
    }
    int l = cur % 10;
    if (l + K < 10)
      dfs(N - 1, K, cur * 10 + l + K, ans);
    if (l >= K && K != 0)
      dfs(N - 1, K, cur * 10 + l - K, ans);
  }
};

/*
  BFS
*/
class Solution
{
public:
  vector<int> numsSameConsecDiff(int N, int K)
  {
    deque<int> q{1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (N == 1)
      q.push_front(0);
    while (--N)
    {
      int size = q.size();
      while (size--)
      {
        int num = q.front();
        q.pop_front();
        int r = num % 10;
        if (r + K <= 9)
          q.push_back(num * 10 + r + K);
        if (r - K >= 0 && K != 0)
          q.push_back(num * 10 + r - K);
      }
    }
    return vector<int>(cbegin(q), cend(q));
  }
};