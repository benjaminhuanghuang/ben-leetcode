/*
1036. Escape a Large Maze [Hard]

https://leetcode.com/problems/escape-a-large-maze/
*/

#include <vector>
#include <set>
#include <unordered_set>

using namespace std;
/*
https://leetcode.com/problems/escape-a-large-maze/discuss/283505/C%2B%2B-20ms-12.6M-DFS-solution-that-combines-others'-ideal.
*/
class Solution
{
public:
  int dir[8] = {-1, 0, 1, 0, 0, -1, 0, 1};
  set<vector<int>> B;
  vector<int> t;
  vector<int> s;
  int bnum;
  bool dfs(int x, int y, int step)
  {
    if (B.find(vector<int>({x, y})) == B.end())
    {
      B.insert(vector<int>({x, y}));
    }
    if (abs(x - s[0]) + abs(y - s[1]) > bnum || (x == t[0] && y == t[1]))
    {
      return true;
    }
    for (int i = 0; i < 4; i++)
    {
      int dx = x + dir[i * 2];
      int dy = y + dir[i * 2 + 1];
      if (dx < 0 || dx > 999999 || dy < 0 || dy > 999999)
      {
        continue;
      }
      if (B.find(vector<int>({dx, dy})) != B.end())
      {
        continue;
      }
      return dfs(dx, dy, step + 1);
    }
    return false;
  }
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
  {
    bnum = blocked.size();
    if (bnum <= 1)
      return true;
    s = source;
    t = target;
    for (int i = 0; i < blocked.size(); i++)
    {
      B.insert(blocked[i]);
    }
    if (dfs(source[0], source[1], 0))
    {
      B.clear();
      s = target;
      t = source;
      for (int i = 0; i < blocked.size(); i++)
      {
        B.insert(blocked[i]);
      }
      if (dfs(target[0], target[1], 0))
        return true;
    }
    return false;
  }
};