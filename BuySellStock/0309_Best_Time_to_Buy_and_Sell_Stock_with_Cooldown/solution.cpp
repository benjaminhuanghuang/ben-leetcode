/*
309. Best Time to Buy and Sell Stock with Cooldown

Level: Medium

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
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
  Solution: DP
  https://www.youtube.com/watch?v=oL6mRyTn56M
  
  hold[i] = max(hold[i-1], rest[i-1], prices[i])
  sold[i] = hold[i-1] + prices[i]
  rest[i] = max(rest[i-1], sold[i-1])
  
  Time complexity: O(n)

  Space complexity: O(1)
*/

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int sold = 0;
    int rest = 0;
    int hold = INT_MIN;
    for (const int price : prices)
    {
      int prev_sold = sold;
      sold = hold + price;
      hold = max(hold, rest - price);
      rest = max(rest, prev_sold);
    }
    return max(rest, sold);
  }
};

/*
  每天三个选择: buy, sell, rest O(3^N)
*/
class Solution_BruteForce
{
public:
  int maxProfit(vector<int> &prices)
  {
    
  }
};