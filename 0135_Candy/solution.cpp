/*
135. Candy

Level: Hard

https://leetcode.com/problems/candy
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
  https://www.youtube.com/watch?v=sHnbaKcx-Kg
  
  Solution: Greedy

  First pass: left to right, the right one will have one more candy than the left one if taller.

  Second pass: right to left, the left one will be at least one more candy than the right one if taller.
*/

class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    const int n = ratings.size();
    vector<int> ans(n, 1);  // 每个小孩至少一颗

    for (int i = 1; i < n; ++i)
      if (ratings[i] > ratings[i - 1])
        ans[i] = ans[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
      if (ratings[i] > ratings[i + 1])
        ans[i] = max(ans[i], ans[i + 1] + 1);
    return accumulate(begin(ans), end(ans), 0);
  }
};