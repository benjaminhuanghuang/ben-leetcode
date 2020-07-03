/*
215. Kth Largest Element in an Array

Level: Medium

https://leetcode.com/problems/kth-largest-element-in-an-array
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    priority_queue<int, std::vector<int>, std::greater<int>> pq; // lookup of the largest (by default)
    for (int i : nums)
    {
      pq.push(i);

      if (pq.size() > k)
      {
        pq.pop();
      }
    }

    return pq.top();
  }
};