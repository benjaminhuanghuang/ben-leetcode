/*
593. Valid Square

Level: Medium

https://leetcode.com/problems/valid-square
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <numeric>
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
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
  {
    set<int> s{distSqr(p1, p2), distSqr(p1, p3), distSqr(p1, p4), distSqr(p2, p3), distSqr(p2, p4), distSqr(p3, p4)};
    return !s.count(0) && s.size() == 2;
  }

private:
  static inline int distSqr(const vector<int> &p1, const vector<int> &p2)
  {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }
};