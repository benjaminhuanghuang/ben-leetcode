/*
703. Kth Largest Element in a Stream

Level: Easy

https://leetcode.com/problems/kth-largest-element-in-a-stream
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <queue>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class KthLargest
{
private:
  //return the largest (by default use less<int>) element
  priority_queue<int, vector<int>, greater<int>> q;
  int size;

public:
  KthLargest(int k, vector<int> &nums)
  {
    size = k;

    for (int num : nums)
    {
      add(num);
    }
  }

  int add(int val)
  {
    if (q.size() < size)
    {
      q.push(val);
    }
    else if (q.top() < val)
    {
      //获取并删除队首元素
      q.pop();
      q.push(val);
    }
    return q.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */