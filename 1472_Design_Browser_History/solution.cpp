/*
1472. Design Browser History

Level: Medium

https://leetcode.com/problems/design-browser-history
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

class BrowserHistory
{
public:
  BrowserHistory(string homepage) : index_(0)
  {
    urls_.push_back(std::move(homepage));
  }

  // visits url from the current page. It clears up all the forward history.
  void visit(string url)
  {
    while (urls_.size() > index_ + 1)
      urls_.pop_back();
    ++index_;
    urls_.push_back(std::move(url));
  }

  string back(int steps)
  {
    index_ = max(index_ - steps, 0);
    return urls_[index_];
  }

  string forward(int steps)
  {
    index_ = min(index_ + steps, static_cast<int>(urls_.size()) - 1);
    return urls_[index_];
  }

private:
  int index_;
  vector<string> urls_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */