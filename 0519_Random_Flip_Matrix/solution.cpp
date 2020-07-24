/*
519. Random Flip Matrix

Level: Medium

https://leetcode.com/problems/random-flip-matrix
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
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-881-random-flip-matrix/
*/
class Solution
{
public:
  Solution(int n_rows, int n_cols) : rows_(n_rows), cols_(n_cols), n_(rows_ * cols_) {}

  vector<int> flip()
  {
    int index = rand() % n_;
    while (m_.count(index))
      index = rand() % n_;
    m_.insert(index);
    return {index / cols_, index % cols_};
  }

  void reset()
  {
    m_.clear();
    n_ = rows_ * cols_;
  }

private:
  const int rows_;
  const int cols_;
  int n_;
  unordered_set<int> m_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */