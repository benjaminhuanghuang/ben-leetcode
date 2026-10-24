/*
1475. Final Prices With a Special Discount in a Shop

Level: Easy

https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
*/
#include <vector>
#include <string>
#include <stack>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  Monotonic stack
  https://www.youtube.com/watch?v=X98Yc4YtgyA


*/

class Solution
{
public:
  /*
    Time complexity O(n^2)
    Space complexity O(1)
  */
  vector<int> finalPrices_naivse(vector<int> &prices)
  {
    const int n = prices.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (prices[j] <= prices[i])
        {
          prices[i] -= prices[j];
          break;
        }
      }
    }
    return prices;
  }

  /*
    Time complexity O(n)
    Space complexity O(n)
  */
  vector<int> finalPrices(vector<int> &prices)
  {
    stack<int> stack;
    for (int p : prices)
    {
      while (!stack.empty() && stack.top() >= p)
      {
        stack.top() -= p;
        stack.pop();
      }
      stack.push(p);
    }
    return prices;
  }

  /*
    Use index
  */
  vector<int> finalPrices2(vector<int> &prices)
  {
    stack<int> stack;
    for (int i = 0; i < prices.size(); i++)
    {
      while (!stack.empty() && prices[stack.top()] >= prices[i])
      {
        prices[stack.top()] -= prices[i];
        stack.pop();
      }
      stack.push(i);
    }
    return prices;
  }
};