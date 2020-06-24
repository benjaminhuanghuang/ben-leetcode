/*
704. Binary Search

Level: Easy

https://leetcode.com/problems/binary-search
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
  int search(vector<int> &nums, int target)
  {
    int l = 0;
    int r = nums.size();
    // use [l, r)
    while (l < r)
    {
      int mid = l + (r - l) / 2;

      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else
      {
        r = mid;
      }
    }
    return -1;
  }
};