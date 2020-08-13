/*
1094. Car Pooling

Level: Medium

https://leetcode.com/problems/car-pooling
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
  https://zxi.mytechroad.com/blog/heap/leetcode-1094-car-pooling/
*/

class Solution
{
public:
  bool carPooling(vector<vector<int>> &trips, int capacity)
  {
    priority_queue<int> q;
    for (const auto &trip : trips)
    {
      int pick_up = -((trip[1] << 10) | (1 << 9) | trip[0]);
      int drop_off = -((trip[2] << 10) | trip[0]);
      q.push(pick_up);
      q.push(drop_off);
    }
    while (q.size())
    {
      int key = -q.top();
      q.pop();
      int sign = ((key >> 9) & 1) ? 1 : -1;
      int num = key & 0xFF;
      if ((capacity -= sign * num) < 0)
        return false;
    }
    return true;
  }
};