/*
295. Find Median from Data Stream

Level: Hard

https://leetcode.com/problems/find-median-from-data-stream
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <queue>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/leetcode/leetcode-295-find-median-from-data-stream/
  add(num): O(logn)

  findMedian(): O(logn)
*/

class MedianFinder
{
public:
  /** initialize your data structure here. */
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (smaller.empty() || num <= smaller.top())
    {
      smaller.push(num);
    }
    else
    {
      larger.push(num);
    }

    // Step 2: Balence left/right
    if (smaller.size() < larger.size())
    {
      smaller.push(larger.top());
      larger.pop();
    }
    else if (smaller.size() - larger.size() == 2)
    {
      larger.push(smaller.top());
      smaller.pop();
    }
  }

  double findMedian()
  {
    if (smaller.size() > larger.size())
    {
      return static_cast<double>(smaller.top());
    }
    else
    {
      return (static_cast<double>(smaller.top()) + larger.top()) / 2;
    }
  }

private:
  priority_queue<int> smaller;                           // max-heap by default
  priority_queue<int, vector<int>, greater<int>> larger; // min-heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */