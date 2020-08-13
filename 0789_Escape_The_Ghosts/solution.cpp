/*
789. Escape The Ghosts

Level: Medium

https://leetcode.com/problems/escape-the-ghosts
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
  Solution: 
*/

class Solution
{
public:
  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
  {
    const int steps = abs(target[0]) + abs(target[1]);
    for (const auto &g : ghosts)
      if (abs(g[0] - target[0]) + abs(g[1] - target[1]) <= steps)
        return false;
    return true;
  }
};