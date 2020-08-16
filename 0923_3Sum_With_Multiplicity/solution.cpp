/*
923. 3Sum With Multiplicity

Level: Medium

https://leetcode.com/problems/3sum-with-multiplicity
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

  https://zxi.mytechroad.com/blog/math/leetcode-923-3sum-with-multiplicity/
*/

class Solution
{
public:
  int threeSumMulti(vector<int> &A, int target)
  {
    constexpr int kMaxN = 100;
    constexpr int kMod = 1e9 + 7;
    vector<long> c(kMaxN + 1, 0);
    for (int a : A)
      ++c[a];
    long ans = 0;
    for (int i = 0; i <= target; ++i)
    {
      for (int j = i; j <= target; ++j)
      {
        const int k = target - i - j;
        if (k < 0 || k >= c.size() || k < j)
          continue;
        if (!c[i] || !c[j] || !c[k])
          continue;
        if (i == j && j == k)
          ans += (c[i] - 2) * (c[i] - 1) * c[i] / 6;
        else if (i == j && j != k)
          ans += c[i] * (c[i] - 1) / 2 * c[k];
        else if (i != j && j == k)
          ans += c[i] * (c[j] - 1) * c[j] / 2;
        else
          ans += c[i] * c[j] * c[k];
      }
    }
    return ans % kMod;
  }
};