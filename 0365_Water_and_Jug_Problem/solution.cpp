/*
365. Water and Jug Problem

Level: Medium

https://leetcode.com/problems/water-and-jug-problem
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
  bool canMeasureWater(int x, int y, int z)
  {
    return z == 0 || ((x + y >= z) && z % gcd(x, y) == 0);
  }
  int gcd(int x, int y)
  {
    return y == 0 ? x : gcd(y, x % y);
  }
};