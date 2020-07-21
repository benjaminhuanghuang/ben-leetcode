/*
400. Nth Digit

Level: Medium

https://leetcode.com/problems/nth-digit
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
  int findNthDigit(int n)
  {
    long long range_number_length = 1;
    long long num = 1;
    long long range = 9;

    while (n > range * range_number_length)
    {
      n -= range * range_number_length;
      ++range_number_length;

      num += range;
      range *= 10;
    }

    num += (n - 1) / range_number_length;
    return to_string(num).at((n - 1) % range_number_length) - '0';
  }
};