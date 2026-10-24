/*
278. First Bad Version

Level: Easy

https://leetcode.com/problems/first-bad-version
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
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class Solution
{
public:
  int firstBadVersion(int n)
  {
    int l = 1;
    int r = n;
    /*
    Returns the smallest m in range [l, r] such that g(m) is true.
    */
    while (l <= r)
    {
      int mid = (r - l) / 2 + l;
      if (isBadVersion(mid)) // mid is too big
      {
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    return l;  // NOT r
  }
};