/*
384. Shuffle an Array

Level: Medium

https://leetcode.com/problems/shuffle-an-array
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
*/

class Solution
{
public:
  Solution(vector<int> &nums)
  {
    nums_ = std::move(nums);
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset()
  {
    return nums_;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle()
  {
    vector<int> output(nums_);
    const int n = nums_.size();
    for (int i = 0; i < n - 1; ++i)
    {
      // [i, n)
      int j = rand() % (n - i) + i;
      std::swap(output[i], output[j]);
    }
    return output;
  }

private:
  vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */