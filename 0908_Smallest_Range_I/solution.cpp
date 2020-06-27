/*
908. Smallest Range I

Level: Easy

https://leetcode.com/problems/smallest-range-i
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  Find the min/max element of the array.

  min + k v.s. max – k

  ans = max(0, (max – min) – 2 * k))

  Time complexity: O(n)
*/

class Solution
{
public:
  int smallestRangeI(vector<int> &A, int K)
  {
    int a_min = *min_element(begin(A), end(A));
    int a_max = *max_element(begin(A), end(A));
    return max(0, (a_max - a_min) - 2 * K);
  }
};