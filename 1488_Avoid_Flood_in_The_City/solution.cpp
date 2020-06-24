/*
1488. Avoid Flood in The City

Level: Medium

https://leetcode.com/problems/running-sum-of-1d-array
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution
{
public:
  vector<int> avoidFlood_TLE(vector<int> &rains)
  {
    vector<int> ans;

    unordered_map<int, int> lakeCounter;

    for (int i = 0; i < rains.size(); i++)
    {
      if (rains[i] > 0)
      {
        if (lakeCounter[rains[i]])
        {
          return {};
        }
        lakeCounter[rains[i]]++;
        ans.push_back(-1);
      }
      else // is 0
      {
        int findRain = -1;
        for (int j = i + 1; j < rains.size(); j++)
        {
          if (rains[j] > 0 && lakeCounter[rains[j]] > 0)
          {
            findRain = rains[j];
            break;
          }
        }
        if (findRain > 0)
        {
          ans.push_back(findRain);
          lakeCounter[findRain]--;
        }
        else
        {
          ans.push_back(1);
        }
      }
    }
    return ans;
  }
  /*
  https://www.youtube.com/watch?v=8sxeQyumrYc
  
  rains[i] >  0: 下雨, do nothing, ans[i] = -1
  rains[i] == 0: 不下雨, chose a lake and dry the lake, ans[lake]

  每次下雨的时候，看看有没有以前的Sunny day 可以把上次下雨的这个湖抽干

  Time complexity O(NlogN)
  Space complexity O(N)

  */
  vector<int> avoidFlood(vector<int> &rains)
  {
    const int n = rains.size();

    vector<int> ans(n, -1); // do nothing

    unordered_map<int, int> last_rain; // lake->last riany day

    set<int> suns; // synny days

    for (int i = 0; i < n; i++)
    {
      const int lake = rains[i];

      if (lake == 0)
      {
        // It's a sunny day
        suns.insert(i);
        ans[i] = 1; // dry any lake if not used
      }
      else
      {
        // this is a raining day
        if (last_rain.count(lake))
        {
          // find first available sunny day after last rainy day
          // find first element bigger than last_rain[lake]
          auto it = suns.upper_bound(last_rain[lake]);
          if (it == end(suns))
          {
            return {};
          }
          ans[*it] = lake; // mark that day for fixing lake
          suns.erase(it);
        }
        last_rain[lake] = i; // Record the last rain day
      }
    }
    return ans;
  }
};