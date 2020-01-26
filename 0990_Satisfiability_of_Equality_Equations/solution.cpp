/*
990. Satisfiability of Equality Equations [Medium]

https://leetcode.com/problems/satisfiability-of-equality-equations/
*/
#include <numeric>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-123/
Graph, Union Find
First pass: merge all x==y
Sedond pass: check all x!=y, assert (find(x) != find(y))
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
public:
  bool equationsPossible(vector<string> &equations)
  {
    iota(begin(parents_), end(parents_), 0);
    // First pass: merge all x==y
    for (const auto &eq : equations)
      if (eq[1] == '=')
        parents_[find(eq[0])] = find(eq[3]);
    // Sedond pass: check all x!=y, assert (find(x) != find(y))
    for (const auto &eq : equations)
      if (eq[1] == '!' && find(eq[0]) == find(eq[3]))
        return false;
    return true;
  }

private:
  array<int, 128> parents_;
  int find(int x)
  {
    if (x != parents_[x])
      parents_[x] = find(parents_[x]);
    return parents_[x];
  }
};