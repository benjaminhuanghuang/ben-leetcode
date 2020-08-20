/*
1250. Check If It Is a Good Array

Level: Hard

https://leetcode.com/problems/check-if-it-is-a-good-array
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
  https://zxi.mytechroad.com/blog/math/leetcode-1250-check-if-it-is-a-good-array/
*/

class Solution
{
public:
  bool isGoodArray(vector<int> &nums)
  {
    int g = nums[0];
    for (int x : nums)
      g = gcd(g, x);
    return g == 1;
  }
};