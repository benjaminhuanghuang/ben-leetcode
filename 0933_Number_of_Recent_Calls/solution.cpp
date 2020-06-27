/*
933. Number of Recent Calls

Level: Easy

https://leetcode.com/problems/number-of-recent-calls
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
  保留ping 中 与最新记录差小于3000的记录。
*/

class RecentCounter
{
  queue<int> q;
public:
  RecentCounter()
  {
  }

  int ping(int t)
  {
    while (!q.empty() && (t - q.front() > 3000))
      q.pop();
    q.push(t);
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */