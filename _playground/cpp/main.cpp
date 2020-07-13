#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

vector<int> tpSort(vector<vector<int>> &graph, vector<int> &inDegree, int count)
{
  vector<int> ans;
  queue<int> q;

  for (int i = 0; i < count; i++)
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

vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
{
  vector<vector<int>> gGraph(m, vector<int>());
  vector<vector<int>> iGraph(n, vector<int>());

  // For non-group items, add them to their own unique groups.
  for (int i = 0; i < n; i++)
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
  for (int i = 0; i < n; i++)
  {
    for (int from : beforeItems[i])
    {
      itemInDegree[i]++;
      iGraph[from].push_back(i);
    }
  }
  // build group graph
  for (int to = 0; to < group.size(); to++)
  {
    int toGroup = group[to];

    for (int from : beforeItems[to])
    {
      int fromGroup = group[from];
      if (fromGroup != toGroup)
      {
        groupInDegree[toGroup]++;
        gGraph[fromGroup].push_back(toGroup);
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

int main()
{
  int n = 8;
  int m = 2;
  vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
  vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};

  auto ans = sortItems(n, m, group, beforeItems);
  return 0;
}