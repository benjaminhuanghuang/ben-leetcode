/*
658. Find K Closest Elements

Level: Medium

https://leetcode.com/problems/find-k-closest-elements
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
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    int low = 0;
    int high = arr.size() - 1;
    while (high - low >= k)
    {
      if (abs(arr[low] - x) > abs(arr[high] - x))
      {
        low++;
      }
      else
      {
        high--;
      }
    }
    vector<int> result;
    for (int i = low; i <= high; i++)
    {
      result.push_back(arr[i]);
    }
    return result;
  }
};