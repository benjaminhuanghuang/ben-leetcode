/*
731. My Calendar II

Level: Medium

https://leetcode.com/problems/my-calendar-ii
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

class MyCalendarTwo
{
public:
  MyCalendarTwo()
  {
  }

  bool book(int start, int end)
  {
    for (const auto &kv : overlaps_)
      if (max(start, kv.first) < min(end, kv.second))
        return false;

    for (const auto &kv : booked_)
    {
      const int ss = max(start, kv.first);
      const int ee = min(end, kv.second);
      if (ss < ee)
        overlaps_.emplace_back(ss, ee);
    }

    booked_.emplace_back(start, end);
    return true;
  }

private:
  vector<pair<int, int>> booked_;
  vector<pair<int, int>> overlaps_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */