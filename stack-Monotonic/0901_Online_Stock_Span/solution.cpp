/*
901. Online Stock Span

Level: Medium

https://leetcode.com/problems/online-stock-span
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
  Solution: Monotonic Stack
*/

class StockSpanner
{
public:
  StockSpanner()
  {
  }

  int next(int price)
  {
    int span = 1;
    while (!s_.empty() && price >= s_.top().first)
    {
      span += s_.top().second;
      s_.pop();
    }
    s_.emplace(price, span);
    return span;
  }

private:
  stack<pair<int, int>> s_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */