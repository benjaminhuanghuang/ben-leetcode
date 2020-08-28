/*
210. Course Schedule II

https://leetcode.com/problems/course-schedule-ii/

*/
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
  https://www.youtube.com/watch?v=Qqgck2ijUjU
  Graph + DFS Topological sorting 24ms
  Time complexity: O(V+E)
  Space complexity:
*/
class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    // create directed graph
    vector<vector<int>> graph(numCourses);

    for (const auto &p : prerequisites)
      graph[p[1]].push_back(p[0]); //[n,m] 先修m, 再修n

    // create array(stack) to recode visiting status
    // states: 0 = unkonwn, 1 == visiting, 2 = visited
    vector<int> v(numCourses, 0);
    vector<int> ans;

    for (int i = 0; i < numCourses; ++i)
    {
      if (dfs_check_cycle(i, graph, v, ans))
      {
        return {};
      }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }

private:
  bool dfs_check_cycle(int cur, vector<vector<int>> &graph, vector<int> &v, vector<int> &ans)
  {
    if (v[cur] == 1)  // visiting
      return true;
    if (v[cur] == 2)  // visited
      return false;

    v[cur] = 1; // 标记当前node 为 visiting

    for (const int t : graph[cur])
      if (dfs_check_cycle(t, graph, v, ans))
        return true;

    v[cur] = 2;
    ans.push_back(cur);
    return false;
  }
};

/*
  BFS, use queue and indegree
*/
class Solution2
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> indegree(numCourses);
    // step1: calculate in-degree [0,1] 表示0的基础课程是1，有一条边 1->0
    for (const auto &pair : prerequisites)
    {
      indegree[pair[0]]++;
    }

    queue<int> queue;
    // step2: find nodes has 0 in-degree
    for (int i = 0; i < indegree.size(); i++)
    {
      if (indegree[i] == 0)
      {
        queue.push(i);
      }
    }

    // step3: BFS, delete node has 0 in-degree
    vector<int> res;
    while (!queue.empty())
    {
      int pre = queue.front();
      queue.pop();
      res.push_back(pre);
      for (const auto &pair : prerequisites)
      {
        if (pair[1] == pre)
        {
          indegree[pair[0]]--;
          if (indegree[pair[0]] == 0)
          {
            queue.push(pair[0]);
          }
        }
      }
    }

    // There is a cycle
    if (res.size() != numCourses)
      return {};

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> a{{1, 0}};
  s.findOrder(2, a);
}