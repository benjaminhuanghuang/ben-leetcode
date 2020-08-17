/*
826. Most Profit Assigning Work

Level: Medium

https://leetcode.com/problems/most-profit-assigning-work
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-826-most-profit-assigning-work/

  https://www.cnblogs.com/grandyang/p/10264877.html
*/

class Solution
{
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
  {
    const int n = difficulty.size();
    vector<pair<int, int>> jobs; // difficulty, profit

    for (int i = 0; i < n; ++i)
      jobs.emplace_back(difficulty[i], profit[i]);

    std::sort(jobs.begin(), jobs.end());
    std::sort(worker.begin(), worker.end());

    int ans = 0;
    int i = 0;
    int best = 0;
    for (int level : worker)
    {
      while (i < n && level >= jobs[i].first)
        best = max(best, jobs[i++].second);
      ans += best;
    }
    return ans;
  }
};