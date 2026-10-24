/*
739. Daily Temperatures

Level: Medium

https://leetcode.com/problems/daily-temperatures
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <stack>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-739-daily-temperatures/

  Stack

    Use a stack to track indices of future warmer days. From top to bottom: recent to far away.

    Time complexity: O(n)

    Space complexity: O(n)

*/

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &T)
  {
    const int n = T.size();
    stack<int> s;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i)
    {
      while (!s.empty() && T[s.top()] <= T[i])
        s.pop();
      ans[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }
    return ans;
  }
};