/*
225. Implement Stack using Queues

Level: Easy

https://leetcode.com/problems/implement-stack-using-queues

- 232. Implement Queue using Stacks
*/
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class MyStack
{
private:
  queue<int> qData;
  queue<int> qHelper;

public:
  /** Initialize your data structure here. */
  MyStack()
  {
  }

  /** Push element x onto stack. */
  void push(int x)
  {
    qData.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    while (qData.size() > 1)
    {
      qHelper.push(qData.front());
      qData.pop();
    }
    int element = qData.front();
    qData.pop();
    while (!qHelper.empty())
    {
      qData.push(qHelper.front());
      qHelper.pop();
    }
    return element;
  }

  /** Get the top element. */
  int top()
  {
    while (qData.size() > 1)
    {
      qHelper.push(qData.front());
      qData.pop();
    }
    int element = qData.front();
    qHelper.push(qData.front());
    qData.pop();
    while (!qHelper.empty())
    {
      qData.push(qHelper.front());
      qHelper.pop();
    }
    return element;
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return qData.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */