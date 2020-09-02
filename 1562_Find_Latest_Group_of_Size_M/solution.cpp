/*
1562. Find Latest Group of Size M

Level: Medium

https://leetcode.com/problems/find-latest-group-of-size-m
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
  arr[3] = 4, on the 3rd day, flip 4th bit to 1

  https://www.youtube.com/watch?v=Tf9v-fNijac
*/

class Solution
{
public:
  int findLatestStep(vector<int> &arr, int m)
  {
    int n = arr.size();
    arr.insert(arr.begin(), 0);
    int ret = -1;

    if (n == m)
      return n;
    vector<int> day(n + 1);
    for (int i = 1; i <= n; i++)
      day[arr[i]] = i;

    deque<int> dq;

    for (int i = 1; i <= n; i++)
    {
      while (dq.size() > 0 && day[dq.back()] < day[i])
        dq.pop_back();
      while (dq.size() > 0 && i - dq.front() >= m)
        dq.pop_front();
      dq.push_back(i);

      if (i < m)
        continue;

      int maxDay = day[dq.front()];

      int left = INT_MAX, right = INT_MAX;
      if (i - m >= 1)
        left = day[i - m];
      if (i + 1 <= n)
        right = day[i + 1];

      if (maxDay < left && maxDay < right)
        ret = max(ret, min(left, right) - 1);
    }
    return ret;
  }
};