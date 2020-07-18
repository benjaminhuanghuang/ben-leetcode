/*
274. H-Index

Level: Medium

https://leetcode.com/problems/h-index
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
    sort(citations.begin(), citations.end());
    int h = 0;
    for (int i = 0; i < citations.size(); i++)
    {
      // 得到当前的H指数
      // 引用数citations[i]，大于该引用数文献的数量是citations.length - i
      int currH = min(citations[i], (int)citations.size() - i);
      if (currH > h)
      {
        h = currH;
      }
    }
    return h;
  }
};


class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int l = 0;
    int r = n;
    while (l < r)
    {
      int m = l + (r - l) / 2;
      // too high
      if (citations[n - m - 1] <= m)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};