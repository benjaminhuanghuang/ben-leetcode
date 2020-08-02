/*
554. Brick Wall

Level: Medium

https://leetcode.com/problems/brick-wall
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
  https://zxi.mytechroad.com/blog/hashtable/leetcode-554-brick-wall/

  Count boundaries, cut at the location with most common boundaries.

  Time complexity: O(|bricks|)

  Space complexity: O(|bricks|)
*/

class Solution
{
public:
  int leastBricks(vector<vector<int>> &wall)
  {
    unordered_map<int, int> count;
    int max_count = 0;
    for (const auto &bricks : wall)
    {
      int s = 0;
      for (int i = 0; i < bricks.size() - 1; ++i)
      {
        s += bricks[i];
        max_count = max(max_count, ++count[s]);
      }
    }
    return wall.size() - max_count;
  }
};