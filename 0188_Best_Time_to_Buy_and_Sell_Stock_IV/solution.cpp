/*
188. Best Time to Buy and Sell Stock IV

Level: Hard

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
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
  https://blog.csdn.net/u012614906/article/details/61206474

  利用买股票问题的第三个变式，可以构造两个dp数组。

  sell[i]表示第i次卖出后最大持有的金钱

  buy[i]表示第i次买入后最大持有的金钱

  卖出的钱由买入的钱加上当前股票卖出的钱，买入的钱由前一次卖出的钱减去当前买股票花去的，因此可以得到两个转移方程

      sell[j] = max(sell[j], buy[j] + prices[i]);
      buy[j] = max(buy[j], sell[j-1] - prices[i]);
  
*/

class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    if (k > prices.size())
    {
      int res = 0;
      for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i - 1])
          res += prices[i] - prices[i - 1];
      return res;
    }
    vector<int> sell(k + 1, 0), buy(k + 1, INT_MIN);
    for (int i = 0; i < prices.size(); i++)
    {
      for (int j = k; j > 0; j--)
      {
        sell[j] = max(sell[j], buy[j] + prices[i]);
        buy[j] = max(buy[j], sell[j - 1] - prices[i]);
      }
    }
    return sell[k];
  }
};