/*
1356. Sort Integers by The Number of 1 Bits

Level: Easy

https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>
#include <bit>
#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  vector<int> sortByBits(vector<int> &arr)
  {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int count1a = __builtin_popcount(a);
      int count1b = __builtin_popcount(b);
      if (count1a == count1b)
        return a < b;
      return count1a < count1b;
    });
    return arr;
  }
};