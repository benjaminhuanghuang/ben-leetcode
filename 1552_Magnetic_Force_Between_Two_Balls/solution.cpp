/*
1552. Magnetic Force Between Two Balls

Level: Medium

https://leetcode.com/problems/magnetic-force-between-two-balls
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
  Solution: Binary Search
  Find the max distance that we can put m balls.

    Time complexity: O(n*log(distance))
    Space complexity: O(1)
*/

class Solution
{
public:
  int maxDistance(vector<int> &position, int m)
  {
    const int n = position.size();
    sort(begin(position), end(position));
    auto count = [&](int d) -> int {
      int last = position[0];
      int ans = 1;
      for (int x : position)
      {
        if (x - last >= d)
        {
          last = x;
          ++ans;
        }
      }
      return ans;
    };
    int l = 0;
    int t = (position.back() - position.front()) + 1;
    int r = t;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (count(t - mid) >= m) // find min of l => max of t - l
        r = mid;
      else
        l = mid + 1;
    }
    return t - l;
  }
};