/*
1539. Kth Missing Positive Number

Level: Easy

https://leetcode.com/problems/kth-missing-positive-number
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
  int findKthPositive(vector<int> &arr, int k)
  {
    unordered_set<int> s(begin(arr), end(arr));
    for (int i = 1; i <= arr.back(); ++i)
    {
      if (!s.count(i))
        --k;
      if (k == 0)
        return i;
    }
    return arr.back() + k;
  }
};

/*
 Binary Search

  We can find the smallest index l using binary search, s.t.
  arr[l] – l + 1 >= k
  which means we missed at least k numbers at index l.
  And the answer will be l + k.

  Time complexity: O(logn)
  Space complexity: O(1)
*/
class Solution
{
public:
  int findKthPositive(vector<int> &arr, int k)
  {
    int l = 0;
    int r = arr.size();
    while (l < r)
    {
      int m = l + (r - l) / 2;
      if (arr[m] - (m + 1) >= k)
        r = m;
      else
        l = m + 1;
    }
    return l + k;
  }
};