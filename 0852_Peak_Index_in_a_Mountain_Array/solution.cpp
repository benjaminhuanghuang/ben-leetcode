/*
852. Peak Index in a Mountain Array

Level: Easy

https://leetcode.com/problems/peak-index-in-a-mountain-array
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

class Solution
{
public:
  /*
    Time complexity: O(logn)
  */
  int peakIndexInMountainArray(vector<int> &A)
  {
    int left = 0;
    int right = A.size();

    int mid = 0;
    while (left < right)
    {
      mid = left + (right - left) / 2;
      if (A[mid] > A[mid + 1]) // right section
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  /*
    Time complexity: O(n)
  */
  int peakIndexInMountainArray(vector<int> &A)
  {
    for (int i = 1; i < A.size(); ++i)
      if (A[i] < A[i - 1])
        return i - 1;
  }
};