/*
1381. Design a Stack With Increment Operation

Level: Medium

https://leetcode.com/problems/design-a-stack-with-increment-operation
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
  Time complexity:
    init: O(1)
    pop: O(1)
    push: O(1)
    inc: O(k)
*/

class CustomStack
{
public:
  CustomStack(int maxSize) : max_size_(maxSize)
  {
  }

  void push(int x)
  {
    if (data_.size() == max_size_)
      return;
    data_.push_back(x);
  }

  int pop()
  {
    if (data_.empty())
      return -1;
    int val = data_.back();
    data_.pop_back();
    return val;
  }

  void increment(int k, int val)
  {
    int n = min(static_cast<size_t>(k), data_.size());
    for (int i = 0; i < n; ++i)
      data_[i] += val;
  }

private:
  int max_size_;
  vector<int> data_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */