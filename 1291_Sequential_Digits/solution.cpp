/*
1291. Sequential Digits

Level: Medium

https://leetcode.com/problems/sequential-digits
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
  vector<int> sequentialDigits(int low, int high)
  {
    queue<int> q;
    for (int i = 1; i <= 9; ++i)
      q.push(i);
    vector<int> res;
    while (!q.empty())
    {
      auto t = q.front();
      q.pop();
      if (t > high)
        break;
      if (t >= low && t <= high)
      {
        res.push_back(t);
      }
      if (t % 10 == 9)
        continue;
      q.push(t * 10 + t % 10 + 1);
    }
    return res;
  }
};