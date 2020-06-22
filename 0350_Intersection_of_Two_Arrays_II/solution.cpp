/*
350. Intersection of Two Arrays II

Level: Easy

https://leetcode.com/problems/intersection-of-two-arrays-ii
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
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> intersection;

    int i = 0, j = 0;
    int index = 0;
    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] == nums2[j])
      {
        intersection.push_back(nums1[i]);
        i++;
        j++;
      }
      else if (nums1[i] < nums2[j])
      {
        i++;
      }
      else
      {
        j++;
      }
    }

    return intersection;
  }
};