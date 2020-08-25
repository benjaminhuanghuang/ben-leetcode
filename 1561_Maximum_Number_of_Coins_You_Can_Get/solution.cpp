/*
1561. Maximum Number of Coins You Can Get

Level: Medium

https://leetcode.com/problems/maximum-number-of-coins-you-can-get
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
  https://zxi.mytechroad.com/blog/uncategorized/leetcode-1561-maximum-number-of-coins-you-can-get/

  
*/

class Solution
{
public:
  int maxCoins(vector<int> &piles)
  {
    const int n = piles.size() / 3;
    sort(begin(piles), end(piles));
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += piles[n * 3 - 2 - i * 2];
    return ans;
  }
};