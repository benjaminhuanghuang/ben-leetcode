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
https://ttzztt.gitbooks.io/lc/content/sort/bucket-sort/campus-bikes.html

Solution: Bucket Sort T: O(M *N), S: O(M * N)
*/


/*
https://www.youtube.com/watch?v=omEQ3PL0XRc&ab_channel=CatRacket


1. 先计算出所有的 worker 和 bike 的距离
2. create map  {distance: {worker, bike}}
3. 根据距离从小到大，分配bike


0 <= workers[i][j], bikes[i][j] < 1000 说明地图最多 1000 格

*/

class Solution
{
public:
  vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
  {
    // 0 <= workers[i][j], bikes[i][j] < 1000 说明地图最多 1000 格
    // 最大距离只能是 2000
    vector<vector<pair<int, int>>> bucket(2001);

    // T: O(M * N); S: O(M * N)
    // range of keys is known: [0, 2000] -> key -> (worker id, bike id)
    int n = workers.size(), m = bikes.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        bucket[dis].push_back({i, j});
      }
    }

    vector<int> ans(n, -1);  // size of worker
    vector<bool> bikeUsed(m, false);

    for (int d = 0; d <= 2000; d++)
    {
      for (int k = 0; k < bucket[d].size(); k++)
      {
        if (ans[bucket[d][k].first] == -1 && !bikeUsed[bucket[d][k].second])
        {
          bikeUsed[bucket[d][k].second] = true;
          ans[bucket[d][k].first] = bucket[d][k].second;
        }
      }
    }

    return ans;
  }
};

