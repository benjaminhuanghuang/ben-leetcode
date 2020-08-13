/*
1227. Airplane Seat Assignment Probability

Level: Medium

https://leetcode.com/problems/airplane-seat-assignment-probability
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

class Solution
{
public:
  double nthPersonGetsNthSeat(int n)
  {
    return n > 1 ? 0.5 : 1;
  }
};