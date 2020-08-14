/*
1296. Divide Array in Sets of K Consecutive Numbers

Level: Medium

https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers
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
  Solution: 
*/

class Solution
{
public:
  bool isPossibleDivide(vector<int> &nums, int k)
  {
    if (nums.size() % k)
      return false;
    map<int, int> m;
    for (int num : nums)
      ++m[num];
    while (m.size())
    {
      const int s = m.cbegin()->first;
      for (int i = 0; i < k; ++i)
      {
        auto it = m.find(s + i);
        if (it == m.cend())
          return false;
        if (--it->second == 0)
          m.erase(it);
      }
    }
    return true;
  }
};