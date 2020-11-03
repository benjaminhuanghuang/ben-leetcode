/*

LeetCode 1066: Campus Bikes II

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
#include <climits>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  https://www.youtube.com/watch?v=1PYYeKwMEAQ&ab_channel=CatRacket
  排列组合
*/

class Solution
{
public:
  int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
  {
    int n = workers.size();
    int m = bikes.size();
    int res = INT_MAX;
    vector<int> usedBike(m, 0 );
    // i is the worder, curr is current sum of distance
    auto dfs = [&](int i, int curr){
      if(i == n)
      {
        res= min(res, curr);
        return;
      }
      // all bike
      for(int j =0; i < m; j++){
        if(usedBike[j])
        {
          continue;
        }
        int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        curr += dis;
        usedBike[j] = 1;
        dfs(i+1, curr);
        curr-= dis; 
        usedBike[j] = 0;
      }
    };

    dfs(0,0);
    return res;
  }
};

class Solution
{
public:
  int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
  {
    int n = bikes.size();
    vector<int> dp(1 << n);
    return dfs(workers, 0, bikes, 0, dp);
  }

private:
  int dfs(vector<vector<int>> &workers, int workerIndex, vector<vector<int>> &bikes, int state, vector<int> &dp)
  {
    if (workerIndex == workers.size())
    {
      return 0;
    }

    if (dp[state] != 0)
    {
      return dp[state];
    }

    int min_dist = INT_MAX;
    for (int i = 0; i < bikes.size(); i++)
    {
      if ((state & (1 << i)) == 0)
      {
        min_dist = min(min_dist, dist(workers[workerIndex], bikes[i]) + dfs(workers, workerIndex + 1, bikes, state | (1 << i), dp));
      }
    }

    dp[state] = min_dist;
    return min_dist;
  }

  int dist(vector<int> &a, vector<int> &b)
  {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }
};