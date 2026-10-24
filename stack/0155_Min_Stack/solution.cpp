/*
155. Min Stack

Level: Easy

https://leetcode.com/problems/min-stack
*/
#include <vector>
#include <string>
#include <stack>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class MinStack
{
private:
  stack<int> valStack;
  stack<int> minStack;

public:
  /** initialize your data structure here. */
  MinStack()
  {
  }

  void push(int x)
  {
    valStack.push(x);
    if (minStack.empty())
    {
      minStack.push(x);
    }
    else
    {
      minStack.push(min(x, minStack.top()));
    }
  }

  void pop()
  {
    valStack.pop();
    minStack.pop();
  }

  int top()
  {
    return valStack.top();
  }

  int getMin()
  {
    return minStack.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */