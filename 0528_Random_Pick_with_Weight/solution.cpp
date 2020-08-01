/*
528. Random Pick with Weight

Level: Medium

https://leetcode.com/problems/random-pick-with-weight
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
  Solution(vector<int> &w) : sums_(std::move(w))
  {
    // <numeric> partial_sum 对于1,2,3 产生序列 1, 3, 6
    partial_sum(begin(sums_), end(sums_), begin(sums_));
  }

  int pickIndex()
  {
    int s = rand() % sums_.back();  // [0, n)
    //upper_bound() 函数查找第一个大于目标值的数，lower_bound() 函数是找到第一个不小于目标值的
    return upper_bound(begin(sums_), end(sums_), s) - begin(sums_);
  }

private:
  vector<int> sums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */