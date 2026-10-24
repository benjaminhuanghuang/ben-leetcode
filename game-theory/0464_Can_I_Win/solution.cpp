/*
464. Can I Win

Level: Medium

https://leetcode.com/problems/can-i-win
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
  http://zxi.mytechroad.com/blog/searching/leetcode-464-can-i-win/
*/

class Solution
{
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal)
  {
    const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (sum < desiredTotal)
      return false;

    if (desiredTotal <= 0)
      return true;
  
    m_ = vector<char>(1 << maxChoosableInteger, 0);
    return canIWin(maxChoosableInteger, desiredTotal, 0);
  }

private:
  vector<char> m_; // 0: unknown, 1: won, -1: lost
  bool canIWin(int M, int T, int state)
  {
    if (T <= 0)
      return false;
    if (m_[state])
      return m_[state] == 1;
    for (int i = 0; i < M; ++i)
    {
      if (state & (1 << i))
        continue; // number i used
      // The next player can not win, current player wins
      if (!canIWin(M, T - (i + 1), state | (1 << i)))
        return m_[state] = 1;
    }
    // Current player loses.
    m_[state] = -1;
    return false;
  }
};