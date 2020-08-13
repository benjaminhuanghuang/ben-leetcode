/*
1447. Simplified Fractions

Level: Medium

https://leetcode.com/problems/simplified-fractions
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
  std::gcd is available since c++17.

  Time complexity: O(n^2logn)
  Space complexity: O(1)
*/

class Solution
{
private:
  int gcd(int x, int y)
  {
    if (x == 0)
      return y;
    return gcd(y % x, x);
  }

public:
  vector<string> simplifiedFractions(int n)
  {
    vector<string> ans;
    for (int i = 1; i < n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (gcd(i, j) == 1)
          ans.push_back(to_string(i) + "/" + to_string(j));
    return ans;
  }
};