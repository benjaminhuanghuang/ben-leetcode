/*
1424. Diagonal Traverse II

Level: Medium

https://leetcode.com/problems/diagonal-traverse-ii
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
  Use diagonal index (i + j) as key.

    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums)
  {
    vector<vector<int>> m;
    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < nums[i].size(); ++j)
      {
        if (m.size() <= i + j)
          m.push_back({});
        m[i + j].push_back(nums[i][j]);
      }
    vector<int> ans;
    for (const auto &d : m)
      ans.insert(end(ans), rbegin(d), rend(d));
    return ans;
  }
};