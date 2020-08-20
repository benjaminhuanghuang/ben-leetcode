/*
1359. Count All Valid Pickup and Delivery Options

Level: Hard

https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options
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
  https://www.youtube.com/watch?v=_OKIln4iieM
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1359-count-all-valid-pickup-and-delivery-options/
*/

class Solution
{
public:
  int countOrders(int n)
  {
    constexpr int kMod = 1e9 + 7;
    long ans = 1;
    for (int i = 2; i <= n; ++i)
      ans = ans * i * (2 * i - 1) % kMod;
    return ans;
  }
};