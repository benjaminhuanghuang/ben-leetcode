/*
895. Maximum Frequency Stack

Level: Hard

https://leetcode.com/problems/maximum-frequency-stack
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

class FreqStack
{
public:
  FreqStack()
  {
  }

  void push(int x)
  {
    int key = (++f_[x] << 16) | (++seq_);
    q_.emplace(key, x);
  }

  int pop()
  {
    int x = q_.top().second;
    q_.pop();
    if (--f_[x] == 0)
      f_.erase(x);
    return x;
  }

private:
  int seq_ = 0;
  unordered_map<int, int> f_;        // {x -> freq}
  priority_queue<pair<int, int>> q_; // {freq | seq_, x}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */