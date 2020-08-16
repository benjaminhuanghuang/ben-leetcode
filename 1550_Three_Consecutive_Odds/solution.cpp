/*
1550. Three Consecutive Odds

Level: Easy

https://leetcode.com/problems/three-consecutive-odds
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
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    bool find = false;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] & 1 == 1) // is odd
      {
        if (find)
        {
          sum++;
          if (sum == 3)
          {
            return true;
          }
        }
        else
        {
          find = true;
          sum = 1;
        }
      }
      else
      {
        find = false;
        sum = 0;
      }
    }
    return false;
  }
};