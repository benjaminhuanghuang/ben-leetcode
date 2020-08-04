/*
622. Design Circular Queue

Level: Medium

https://leetcode.com/problems/design-circular-queue
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

class MyCircularQueue
{
public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) : q_(k)
  {
  }

  /** Insert an element into the circular queue. Return true if the operation is successful. */
  bool enQueue(int value)
  {
    if (isFull())
      return false;
    q_[(head_ + size_) % q_.size()] = value;
    ++size_;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is successful. */
  bool deQueue()
  {
    if (isEmpty())
      return false;
    head_ = (head_ + 1) % q_.size();
    --size_;
    return true;
  }

  /** Get the front item from the queue. */
  int Front()
  {
    return isEmpty() ? -1 : q_[head_];
  }

  /** Get the last item from the queue. */
  int Rear()
  {
    return isEmpty() ? -1 : q_[(head_ + size_ - 1) % q_.size()];
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty()
  {
    return size_ == 0;
  }

  /** Checks whether the circular queue is full or not. */
  bool isFull()
  {
    return size_ == q_.size();
  }

private:
  vector<int> q_;
  int head_ = 0;
  int size_ = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */