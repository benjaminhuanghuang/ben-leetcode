/*
1389. Create Target Array in the Given Order

Level: Easy

https://leetcode.com/problems/create-target-array-in-the-given-order
*/
#include <vector>
#include <string>
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
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
  {
    vector<int> arr;

    for (int i = 0; i < nums.size(); i++)
    {
      arr.insert(arr.begin() + index[i], nums[i]);
    }

    return arr;
  }
};