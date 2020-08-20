/*
352. Data Stream as Disjoint Intervals

Level: Hard

https://leetcode.com/problems/data-stream-as-disjoint-intervals
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.tutorialspoint.com/data-stream-as-disjoint-intervals-in-cplusplus
*/

class SummaryRanges
{
public:
  set<int> nums;
  int low, high;
  SummaryRanges()
  {
    low = INT_MAX;
    high = INT_MIN;
  }
  void addNum(int val)
  {
    nums.insert(val);
  }
  vector<vector<int>> getIntervals()
  {
    vector<vector<int>> ret;
    set<int>::iterator it = nums.begin();
    while (it != nums.end())
    {
      int x = *it;
      if (ret.empty() || ret.back()[1] + 1 < x)
      {
        ret.push_back({x, x});
      }
      else
      {
        ret.back()[1]++;
      }
      it++;
    }
    return ret;
  }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */