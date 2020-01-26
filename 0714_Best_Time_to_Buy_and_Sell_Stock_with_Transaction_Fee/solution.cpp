/*
714. Best Time to Buy and Sell Stock with Transaction Fee

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/
#include <vector>
using namespace std;

/*
https://blog.csdn.net/Zarlove/article/details/78323469
*/
class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
  }
};

class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    int sold = 0, hold = -prices[0];
    for (int price : prices)
    {
      int t = sold;
      sold = max(sold, hold + price - fee);
      hold = max(hold, t - price);
    }
    return sold;
  }
};