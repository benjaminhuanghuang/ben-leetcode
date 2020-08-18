/*
1402. Reducing Dishes

Level: Hard

https://leetcode.com/problems/reducing-dishes
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

class Solution_BruteForce
{
public:
  int maxSatisfaction(vector<int> &s)
  {
    const int n = s.size();
    sort(begin(s), end(s));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      int v = 0;
      for (int j = i; j < n; ++j)
        v += s[j] * (j - i + 1);
      ans = max(ans, v);
    }
    return ans;
  }
};

/*
  Solution: 
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1402-reducing-dishes/
*/

class Solution
{
public:
  int maxSatisfaction(vector<int> &satisfaction)
  {
    const int n = satisfaction.size();
    sort(rbegin(satisfaction), rend(satisfaction));
    int ans = 0;
    int prefix = 0;
    for (int v : satisfaction)
    {
      prefix += v;
      if (prefix <= 0)
        break;
      ans += prefix;
    }
    return ans;
  }
};