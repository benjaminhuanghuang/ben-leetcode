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
  Solution: Buckets
  https://zxi.mytechroad.com/blog/desgin/leetcode-895-maximum-frequency-stack/

*/
class FreqStack
{
public:
  FreqStack() {}

  void push(int x)
  {
    auto it = freq_.find(x);
    if (it == freq_.end())
      it = freq_.emplace(x, 0).first;
    int freq = ++it->second;
    if (stacks_.size() < freq)
      stacks_.push_back({});
    stacks_[freq - 1].push(x);
  }

  int pop()
  {
    int x = stacks_.back().top();
    stacks_.back().pop();
    if (stacks_.back().empty())
      stacks_.pop_back();
    auto it = freq_.find(x);
    if (!(--it->second))
      freq_.erase(it);
    return x;
  }

private:
  vector<stack<int>> stacks_;
  unordered_map<int, int> freq_;
};


/*
  Solution2: Priority Queue
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