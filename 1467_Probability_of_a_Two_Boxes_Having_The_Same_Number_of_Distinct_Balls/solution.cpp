/*
1467. Probability of a Two Boxes Having The Same Number of Distinct Balls

Level: Hard

https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls
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

  https://zxi.mytechroad.com/blog/searching/leetcode-1467-probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/
  
*/
class Solution
{
public:
  double getProbability(vector<int> &balls)
  {
    const int k = balls.size();
    const int n = accumulate(begin(balls), end(balls), 0);
    vector<double> fact(49, 1.0);
    for (int i = 1; i < fact.size(); ++i)
      fact[i] = fact[i - 1] * i;
    auto perms = [&](const vector<int> &bs, int n) -> double {
      double p = fact[n];
      for (int b : bs)
        p /= fact[b];
      return p;
    };
    vector<int> box1, box2;
    function<double(int)> dfs = [&](int d) -> double {
      const int n1 = accumulate(begin(box1), end(box1), 0);
      const int n2 = accumulate(begin(box2), end(box2), 0);
      if (n1 > n / 2 || n2 > n / 2)
        return 0;
      if (d == k)
        return (box1.size() == box2.size()) * perms(box1, n1) * perms(box2, n2);
      double total = 0;
      for (int s1 = 0; s1 <= balls[d]; ++s1)
      {
        const int s2 = balls[d] - s1;
        if (s1)
          box1.push_back(s1);
        if (s2)
          box2.push_back(s2);
        total += dfs(d + 1);
        if (s1)
          box1.pop_back();
        if (s2)
          box2.pop_back();
      }
      return total;
    };
    return dfs(0) / perms(balls, n);
  }
};