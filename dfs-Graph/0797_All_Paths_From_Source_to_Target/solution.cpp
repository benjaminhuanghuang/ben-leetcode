/*
797. All Paths From Source to Target

Level: Medium

https://leetcode.com/problems/all-paths-from-source-to-target
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
  Input [[1,2],[3],[3],[]] 表示 0-1 0-2,  1-3, 2-3

  Solution: 
  DFS
    Time complexity: O(n!)

    Space complexity: O(n)
*/

class Solution
{
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    vector<vector<int>> ans;
    vector<int> path{0};
    dfs(graph, path, ans);
    return ans;
  }

private:
  void dfs(const vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans)
  {
    if (path.back() == graph.size() - 1)
    {
      ans.push_back(path);
      return;
    }

    for (int next : graph[path.back()])
    {
      path.push_back(next);
      dfs(graph, path, ans);
      path.pop_back();
    }
  }
};