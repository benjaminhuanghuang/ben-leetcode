/*
335. Self Crossing

Level: Hard

https://leetcode.com/problems/self-crossing
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
  https://www.cnblogs.com/grandyang/p/5216856.html
*/

class Solution
{
public:
  bool isSelfCrossing(vector<int> &x)
  {
    for (int i = 3; i < x.size(); ++i)
    {
      if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1])
      {
        return true;
      }
      if (i >= 4 && x[i - 1] == x[i - 3] && x[i] >= x[i - 2] - x[i - 4])
      {
        return true;
      }
      if (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 3] >= x[i - 1] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i] >= x[i - 2] - x[i - 4])
      {
        return true;
      }
    }
    return false;
  }
};