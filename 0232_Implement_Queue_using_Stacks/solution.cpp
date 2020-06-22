/*
232. Implement Queue using Stacks

Level: Easy

https://leetcode.com/problems/implement-queue-using-stacks

- 225. Implement Stack using Queues
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class MyQueue
{

private:
  stack<int> sIn;
  stack<int> sOut;

public:
  /** Initialize your data structure here. */
  MyQueue()
  {
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    sIn.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    if(sOut.empty())
    {
      while(!sIn.empty())
      {
        sOut.push(sIn.top());
        sIn.pop();
      }
    }

    int val = sOut.top();
    sOut.pop();
    return val;
  }

  /** Get the front element. */
  int peek()
  {
    if(sOut.empty())
    {
      while(!sIn.empty())
      {
        sOut.push(sIn.top());
        sIn.pop();
      }
    }

    return sOut.top();
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return sIn.empty() && sOut.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */