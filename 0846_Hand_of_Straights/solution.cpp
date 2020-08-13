/*
846. Hand of Straights

Level: Medium

https://leetcode.com/problems/hand-of-straights
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: Greedy

    Time complexity: O(nlogn)

    Space complexity: O(n)
*/

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int W)
  {
    map<int, int> counts;
    for (int h : hand)
      ++counts[h];
      
    while (!counts.empty())
    {
      auto it = counts.begin();
      int start = it->first;
      for (int j = 0; j < W; ++j)
      {
        if (it == counts.end() || it->first != start + j)
          return false;
        auto prev = it++;
        if (--(prev->second) == 0)
          counts.erase(prev);
      }
    }
    return true;
  }
};