/*
1298. Maximum Candies You Can Get from Boxes

Level: Hard

https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes
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
  Solution: BFS

  https://zxi.mytechroad.com/blog/searching/leetcode-1298-maximum-candies-you-can-get-from-boxes/
*/

class Solution
{
public:
  int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
  {
    vector<int> found(status.size());
    vector<int> hasKeys(status);
    queue<int> q;

    for (int b : initialBoxes)
    {
      found[b] = 1;
      if (hasKeys[b])
        q.push(b);
    }

    int ans = 0;
    while (!q.empty())
    {
      int b = q.front();
      q.pop();
      ans += candies[b];
      for (int t : containedBoxes[b])
      {
        found[t] = 1;
        if (hasKeys[t])
          q.push(t);
      }
      for (int t : keys[b])
      {
        if (!hasKeys[t] && found[t])
          q.push(t);
        hasKeys[t] = 1;
      }
    }

    return ans;
  }
};