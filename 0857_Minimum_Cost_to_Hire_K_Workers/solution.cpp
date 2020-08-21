/*
857. Minimum Cost to Hire K Workers

Level: Hard

https://leetcode.com/problems/minimum-cost-to-hire-k-workers
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
#include <cfloat>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  https://www.cnblogs.com/grandyang/p/11329482.html
*/

class Solution
{
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K)
  {
    double res = DBL_MAX, qsum = 0, n = quality.size();
    vector<pair<double, int>> workers;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i)
    {
      workers.push_back({double(wage[i]) / quality[i], quality[i]});
    }
    sort(workers.begin(), workers.end());
    for (auto worker : workers)
    {
      qsum += worker.second;
      pq.push(worker.second);
      if (pq.size() > K)
      {
        qsum -= pq.top();
        pq.pop();
      }
      if (pq.size() == K)
      {
        res = min(res, qsum * worker.first);
      }
    }
    return res;
  }
};