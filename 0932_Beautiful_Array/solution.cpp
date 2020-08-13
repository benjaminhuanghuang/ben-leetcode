/*
932. Beautiful Array

Level: Medium

https://leetcode.com/problems/beautiful-array
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
  https://blog.csdn.net/lwgkzl/article/details/83502656
*/

class Solution
{
public:
  vector<int> beautifulArray(int N)
  {
    vector<int> ans;
    if (N == 1)
    {
      ans.push_back(1);
      return ans;
    }
    else
    {
      vector<int> ve = beautifulArray((N + 1) / 2);
      int sz = ve.size();
      for (int it = 0; it < sz; it++)
        ans.push_back(2 * ve[it] - 1);
      vector<int> vv = beautifulArray(N / 2);
      sz = vv.size();
      for (int it = 0; it < sz; it++)
        ans.push_back(2 * vv[it]);
    }
    return ans;
  }
};