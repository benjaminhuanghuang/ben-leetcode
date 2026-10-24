/*
275. H-Index II

Level: Medium

https://leetcode.com/problems/h-index-ii
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
  int hIndex(vector<int> &citations)
  {
    for (int i = 1; i <= citations.size(); ++i)
      if (*(citations.rbegin() + i - 1) < i)
        return i - 1;
    return citations.size();
  }
};

/*
  Time Complexity: O(logn)

  Space Complexity: O(1)
*/
class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    int n = citations.size();
    int l = 0;
    int r = n;
    while (l < r)
    {
      int m = l + (r - l) / 2;
      // too high
      // citations[n - m - 1]
      if (citations[n - m - 1] <= m)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    int n = citations.size();
    int l = 0;
    int r = n;
    while (l < r)
    {
      int m = l + (r - l) / 2;
      // 如果该点是有效的H指数，则最大H指数一定在右边
      if (citations[m] < n - m)
      {
        l = m + 1;
      }
      else
      {
        // 否则最大H指数在左边
        r = m;
      }
    }
    return n - l;
  }
};