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
#include <set>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  所有无人认领的小组分配一个组号，这个组内只有这一个项目。
  接下来统计一下每个组之间边关系和入度，因为是统计组之间的，所有组内依赖暂时不考虑，还需要考虑的是如果两个组之间有多条边，我们只计算一次。
  同时，统计每一个组内部的边关系和入度，因为是统计组内的，所以组间依赖关系暂时不考虑。
  对组进行拓扑排序，看一下是否有冲突，如果有冲突就返回，否则继续。
  按照组的拓扑序，对每一个组内部进行拓扑排序。
*/

class Solution
{
public:
  vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
  {
    unordered_map<int, set<int>> group_to_item_hash;
    // item items do not belong to group to new group
    for (int i = 0; i < n; i++)
    {
      if (group[i] == -1)
      {
        group[i] = m++;
      }
      group_to_item_hash[group[i]].insert(i);
    }

    // build graph
    vector<set<int>> group_graph(m, set<int>()), item_graph(n, set<int>());
    vector<int> group_indegree(m, 0);
    vector<int> item_indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (beforeItems[i].size() == 0)
        continue;
      for (auto from : beforeItems[i]) // i is to
      {
        if (group[from] != group[i]) // beforeItem is in different group
        {
          if (group_graph[group[from]].count(group[i]) == 0)
          {
            group_graph[group[from]].insert(group[i]);
            group_indegree[group[i]]++;
          }
        }
        else
        {
          item_graph[from].insert(i);
          item_indegree[i]++;
        }
      }
    }

    vector<int> group_ordered = tpSort(group_graph, group_indegree);

    if (group_ordered.size() != m)
      return {};

    vector<int> ans;
    for (auto group_id : group_ordered)
    {
      queue<int> q;
      for (auto item_id : group_to_item_hash[group_id])
      {
        if (item_indegree[item_id] == 0)
          q.push(item_id);
      }
      int count = 0;
      while (!q.empty())
      {
        int p = q.front();
        q.pop();
        ans.push_back(p);
        count++;
        for (auto next : item_graph[p])
        {
          item_indegree[next]--;
          if (item_indegree[next] == 0)
            q.push(next);
        }
      }
      if (count != group_to_item_hash[group_id].size())
        return {};
    }
    return ans;
  }

  vector<int> tpSort(vector<set<int>> &graph, vector<int> &in_degree)
  {
    vector<int> sorted;
    queue<int> q;

    for (int i = 0; i < in_degree.size(); i++)
    {
      if (in_degree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      sorted.push_back(cur);

      for (int next : graph[cur])
      {
        in_degree[next]--;
        if (in_degree[next] == 0)
        {
          q.push(next);
        }
      }
    }
    return sorted;
  }
};