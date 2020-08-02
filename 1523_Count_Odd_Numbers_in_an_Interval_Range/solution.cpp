/*
1523. Count Odd Numbers in an Interval Range

Level: Easy

https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
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
  int countOdds(int low, int high)
  {
    int n = high - low + 1;
    if ((low & 1) && (n & 1)) // odd
    {
      return n / 2 + 1;
    }
    return n / 2;
  }
};