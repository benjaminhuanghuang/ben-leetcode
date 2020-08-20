/*
1553. Minimum Number of Days to Eat N Oranges

Level: Hard

https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges
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

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1553-minimum-number-of-days-to-eat-n-oranges/
*/

class Solution
{
public:
  int minDays(int n)
  {
    queue<int> q{{n}};
    unordered_set<int> seen;
    int steps = 0;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int x = q.front();
        q.pop();
        if (x == 0)
          return steps;
        if (x % 2 == 0 && seen.insert(x / 2).second)
          q.push(x / 2);
        if (x % 3 == 0 && seen.insert(x / 3).second)
          q.push(x / 3);
        if (seen.insert(x - 1).second)
          q.push(x - 1);
      }
      ++steps;
    }
    return -1;
  }
};