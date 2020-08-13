/*
1362. Closest Divisors

Level: Medium

https://leetcode.com/problems/closest-divisors
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
  https://www.youtube.com/watch?v=lfD39LyHU8U
*/

class Solution
{
public:
  vector<int> closestDivisors(int num)
  {
    for (int i = (int)(sqrt(num + 2)); i >= 1; i--)
    {
      if ((num + 1) % i == 0)
      {
        return {(num + 1) / i, i};
      }
      if ((num + 2) % i == 0)
      {
        return {(num + 2) / i, i};
      }
    }
    return {};
  }
};