/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Level: Medium

https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
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
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    int subArrSum = 0;
    int i = 0;
    for (; i < k; i++)
    {
      subArrSum += arr[i];
    }
    int res = 0;
    // i = k
    while (i < arr.size())
    {
      if (subArrSum / k >= threshold)
      {
        res++;
      }
      subArrSum += arr[i];
      subArrSum -= arr[i - k];
      i++;
    }
    if (subArrSum / k >= threshold)
    {
      res++;
    }
    return res;
  }
};