/*
877. Stone Game

Level: Medium

https://leetcode.com/problems/stone-game
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-877-stone-game/
*/

class Solution
{
public:
  bool stoneGame(vector<int> &piles)
  {
    const int n = piles.size();
    m_ = vector<vector<int>>(n, vector<int>(n, INT_MIN));
    return score(piles, 0, n - 1) > 0;
  }

private:
  vector<vector<int>> m_;
  int score(const vector<int> &piles, int l, int r)
  {
    if (l == r)
      return piles[l];
    if (m_[l][r] == INT_MIN)
      m_[l][r] = max(piles[l] - score(piles, l + 1, r),
                     piles[r] - score(piles, l, r - 1));
    return m_[l][r];
  }
};