/*
454. 4Sum II

Level: Medium

https://leetcode.com/problems/4sum-ii
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
  
  Time complexity: O(n^2)
  Space complexity: O(n^2)
*/

class Solution
{
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
  {
    unordered_map<int, int> sums;
    for (int a : A)
      for (int b : B)
        ++sums[a + b];
    int ans = 0;

    for (int c : C)
      for (int d : D)
      {
        auto it = sums.find(-c - d);
        if (it != sums.end())
          ans += it->second;
      }
    return ans;
  }
};