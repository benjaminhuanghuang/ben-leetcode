/*
121. Best Time to Buy and Sell Stock

Level: Easy

https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/
#include <vector>
#include <climits>

using namespace std;

/*
https://www.youtube.com/watch?v=8pVhUpF1INw&ab_channel=HuaHua

*/


class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
      minPrice = min(minPrice, prices[i]);
      maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
  }
};