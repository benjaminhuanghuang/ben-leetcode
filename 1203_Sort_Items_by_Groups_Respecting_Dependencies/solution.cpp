/*
1203. Sort Items by Groups Respecting Dependencies

Level: Hard

https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies
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
  1. 属于同一group的item要排序
  2. before Items
  Solution: 
*/

class Solution
{
public:
  vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
  {
    vector<vector<int>> gGraph(m, vector<int>());
    vector<vector<int>> iGraph(n, vector<int>());

    // item items do not belong to group to new group
    for (int i = 0; i < group.size(); i++)
    {
      if (group[i] == -1)
      {
        // i-th item belongs to no group
        group[i] = m++;
      }
    }

    vector<int> itemInDegree(n, 0);
    vector<int> groupInDegree(m, 0); // m is increased abrove.

    // build item graph
    for (int to = 0; to < beforeItems.size(); to++)
    {
      int toGroup = group[to];

      for (int from : beforeItems[to])
      {
        itemInDegree[to]++;
        iGraph[from].push_back(to);
      }
    }
    // build group graph
    for (int to = 0; to < group.size(); to++)
    {
      int toGroup = group[to];

      for (int from : beforeItems[to])
      {
        int fromGroup = group[to];
        if (fromGroup != toGroup)
        {
          groupInDegree[toGroup]++;
          gGraph[fromGroup].push_back(to);
        }
      }
    }

    vector<int> iList = tpSort(iGraph, itemInDegree, n);
    vector<int> gList = tpSort(gGraph, groupInDegree, m);

    if (iList.size() == 0 || gList.size() == 0)
      return {};

    vector<vector<int>> groupedList(m, vector<int>());

    for (int item : iList)
    {
      int grp = group[item];

      groupedList[grp].push_back(item);
    }

    vector<int> ans;
    for (int grp : gList)
    {
      for (int item : groupedList[grp])
      {
        ans.push_back(item);
      }
    }
    return ans;
  }

  vector<int> tpSort(vector<vector<int>> &graph, vector<int> &inDegree, int count)
  {
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < inDegree.size(); i++)
    {
      if (inDegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      ans.push_back(cur);

      for (int next : graph[cur])
      {
        inDegree[next]--;
        if (inDegree[next] == 0)
        {
          q.push(next);
        }
      }
    }
    return count == ans.size() ? ans : vector<int>();
  }
};