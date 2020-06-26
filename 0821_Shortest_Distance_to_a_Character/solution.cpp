/*
821. Shortest Distance to a Character

Level: Easy

https://leetcode.com/problems/shortest-distance-to-a-character
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  /*
    Two Pass
      Time complexity: O(n)
      Space complexity: O(n)
  */
  vector<int> shortestToChar(string S, char C)
  {
    const int n = S.length();
    vector<int> ans(n, INT_MAX);
    int index = -1;
    for (int i = 0; i < n; ++i)
    {
      if (S[i] == C)
        index = i;
      if (index < 0)
        continue;
      ans[i] = abs(i - index);
    }
    index = -1;
    for (int i = n - 1; i >= 0; --i)
    {
      if (S[i] == C)
        index = i;
      if (index < 0)
        continue;
      ans[i] = min(ans[i], abs(i - index));
    }
    return ans;
  }

  vector<int> shortestToChar_v2(string S, char C)
  {
    const int n = S.length();
    vector<int> indices(2 * n); // 0, 1, ..., n - 1, n - 1, n - 2, ..., 0
    std::iota(indices.begin(), indices.begin() + n, 0);
    std::iota(indices.rbegin(), indices.rbegin() + n, 0);
    vector<int> ans(n, INT_MAX);
    int index = -n;
    for (int i : indices)
    {
      if (S[i] == C)
        index = i;
      ans[i] = min(ans[i], abs(i - index));
    }
    return ans;
  }
};