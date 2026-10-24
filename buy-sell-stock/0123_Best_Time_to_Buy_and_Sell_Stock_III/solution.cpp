/*
123. Best Time to Buy and Sell Stock III

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/
#include <vector>

using namespace std;
/*
    https://www.programcreek.com/2014/02/leetcode-best-time-to-buy-and-sell-stock-iii-java/
    Comparing to I and II, III limits the number of transactions to 2. This can be solve by "devide and conquer".
    We use left[i] to track the maximum profit for transactions before i, and use right[i] to track the maximum profit
    for transactions after i.

    https://www.youtube.com/watch?v=LX8i5PxRVCg
     */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }

        //max profit in 0 ... i
        vector<int> left(prices.size());
        //max profit from  i ... price.length -1
        vector<int> right(prices.size());

        // DP from left to right
        //left[0] = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }

        // DP from right to left
        //right[prices.length - 1] = 0;
        int maxPrice = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }

        return maxProfit;
    }
};