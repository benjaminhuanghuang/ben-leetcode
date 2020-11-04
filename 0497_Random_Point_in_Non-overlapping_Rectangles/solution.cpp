/*
497. Random Point in Non-overlapping Rectangles

Level: Medium

https://leetcode.com/problems/random-point-in-non-overlapping-rectangles
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
  https://www.youtube.com/watch?v=rj9LuSMdfOQ
*/
class Solution
{
public:
  Solution(vector<vector<int>> rects) : rects_(std::move(rects))
  {
    sums_ = vector<int>(rects_.size());
    for (int i = 0; i < rects_.size(); ++i)
    {
      sums_[i] = (rects_[i][2] - rects_[i][0] + 1) * (rects_[i][3] - rects_[i][1] + 1);
      if (i > 0)
        sums_[i] += sums_[i - 1];
    }
  }

  vector<int> pick()
  {
    const int s = nextInt(sums_.back()) + 1;
    // binary search
    int index = lower_bound(sums_.begin(), sums_.end(), s) - sums_.begin();
    const auto &rect = rects_[index];
    return {rect[0] + nextInt(rect[2] - rect[0] + 1),
            rect[1] + nextInt(rect[3] - rect[1] + 1)};
  }

private:
  vector<int> sums_;
  vector<vector<int>> rects_;

  // Returns a random int in [0, n - 1]
  int nextInt(int n)
  {
    return rand() / static_cast<double>(RAND_MAX) * n;
  }
};

/*
  Solution: 
  https://zxi.mytechroad.com/blog/geometry/leetcode-882-random-point-in-non-overlapping-rectangles/

  # 880. Random Pick with Weight

*/

class Solution
{
public:
  Solution(vector<vector<int>> rects) : rects_(std::move(rects))
  {
    sums_ = vector<int>(rects_.size());
    for (int i = 0; i < rects_.size(); ++i)
    {
      sums_[i] = (rects_[i][2] - rects_[i][0] + 1) * (rects_[i][3] - rects_[i][1] + 1);
      if (i > 0)
        sums_[i] += sums_[i - 1];
    }
  }

  vector<int> pick()
  {
    const int s = nextInt(sums_.back()) + 1;
    // binary search
    int index = lower_bound(sums_.begin(), sums_.end(), s) - sums_.begin();
    const auto &rect = rects_[index];
    return {rect[0] + nextInt(rect[2] - rect[0] + 1),
            rect[1] + nextInt(rect[3] - rect[1] + 1)};
  }

private:
  vector<int> sums_;
  vector<vector<int>> rects_;

  // Returns a random int in [0, n - 1]
  int nextInt(int n)
  {
    return rand() / static_cast<double>(RAND_MAX) * n;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */