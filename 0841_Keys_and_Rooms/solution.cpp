/*
841. Keys and Rooms

https://leetcode.com/problems/keys-and-rooms/
*/
#include <string>
#include <climits>
#include <vector>
#include <unordered_set>

using namespace std;

/*
  http://zxi.mytechroad.com/blog/graph/leetcode-841-keys-and-rooms/

  Solution: DFS, 遍历所有节点
    Time complexity: O(V + E)
    Space complexity: O(V)
*/
class Solution
{
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    unordered_set<int> visited;
    dfs(rooms, 0, visited);
    return visited.size() == rooms.size();
  }

private:
  void dfs(const vector<vector<int>> &rooms, int cur, unordered_set<int> &visited)
  {
    if (visited.count(cur))
      return;
    visited.insert(cur);
    for (int next : rooms[cur])
      dfs(rooms, next, visited);
  }
};