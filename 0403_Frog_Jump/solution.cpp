/*
403. Frog Jump

Level: Hard

https://leetcode.com/problems/frog-jump
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
  https://www.cnblogs.com/grandyang/p/5888439.html
*/
class Solution
{
public:
  bool canCross(vector<int> &stones)
  {
    unordered_map<int, bool> m;
    return helper(stones, 0, 0, m);
  }
  bool helper(vector<int> &stones, int pos, int jump, unordered_map<int, bool> &m)
  {
    int n = stones.size(), key = pos | jump << 11;
    if (pos >= n - 1)
      return true;
    if (m.count(key))
      return m[key];
    for (int i = pos + 1; i < n; ++i)
    {
      int dist = stones[i] - stones[pos];
      if (dist < jump - 1)
        continue;
      if (dist > jump + 1)
        return m[key] = false;
      if (helper(stones, i, dist, m))
        return m[key] = true;
    }
    return m[key] = false;
  }
};