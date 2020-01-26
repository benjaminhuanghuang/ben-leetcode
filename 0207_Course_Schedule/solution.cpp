/*
207. Course Schedule

https://leetcode.com/problems/course-schedule/

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. 
If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
*/
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
  https://www.youtube.com/watch?v=M6SBePBMznU

  Fastes solution, DFS Topological sort 
  Finding cycles O(n^2) -> Topological sort O(N)
   [1,0] 表示有一条边 0->1
*/
class Solution1
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    // create directed graph
    graph_ = vector<vector<int>>(numCourses);

    for (const auto &p : prerequisites)
      graph_[p[1]].push_back(p[0]);    //[n,m] 先修m, 再修n

    // create array(stack) to recode visiting status
    // states: 0 = unkonwn, 1 == visiting, 2 = visited
    vector<int> v(numCourses, 0);

    for (int i = 0; i < numCourses; ++i)
      if (dfs_check_cycle(i, v))
        return false;

    return true;
  }

private:
  vector<vector<int>> graph_;
  bool dfs_check_cycle(int cur, vector<int> &v)
  {
    if (v[cur] == 1)
      return true;
    if (v[cur] == 2)
      return false;

    v[cur] = 1;   // 标记当前node 为 visiting

    for (const int t : graph_[cur])
      if (dfs_check_cycle(t, v))
        return true;

    v[cur] = 2;

    return false;
  }
};

/*
    BFS and remove node has 0 in-degree 
    https://www.youtube.com/watch?v=zkTOIVUdW-I

    in-degree: 有边指向一个node，in this case, 1 in-degree means 1 prerequisite
    这个解法容易理解但是效率不高(48 ms)
   */

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> indegree(numCourses);
    int res = numCourses;
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
    while (!queue.empty())
    {
      int pre = queue.front();
      queue.pop();
      res--;
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
    return res == 0;
  }
};

/*
    Solution 2: DFS Finding cycles

    Time complexity: O(n^2)

    Space complexity: O(n)
    */
class Solution2
{
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
  {

    graph_.clear();

    for (const auto &p : prerequisites)
      graph_[p.first].insert(p.second);

    for (int i = 0; i < numCourses; ++i)
    {
      vector<int> visited(numCourses, 0);
      if (cycle(i, i, visited))
        return false;
    }

    return true;
  }

private:
  unordered_map<int, unordered_set<int>> graph_;

  bool cycle(int start, int curr, vector<int> &visited)
  {
    if (curr == start && visited[start])
      return true;
    if (!graph_.count(curr))
      return false;

    for (const int next : graph_.at(curr))
    {
      if (visited[next])
        continue;
      visited[next] = true;
      if (cycle(start, next, visited))
        return true;
    }
    return false;
  }
};