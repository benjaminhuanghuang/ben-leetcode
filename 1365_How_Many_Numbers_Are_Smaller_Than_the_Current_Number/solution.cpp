/*
1365. How Many Numbers Are Smaller Than the Current Number

Level: Easy

https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
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
  /*
    Time complexity: O(n^2)
    Space complexity: O(1)
  */
  vector<int> smallerNumbersThanCurrent_BruteForce(vector<int> &nums)
  {
    const int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i != j && nums[j] < nums[i])
          ++ans[i];
    return ans;
  }
  /*
  Sort, get distance
  Time complexity: O(nlogn)
  Space complexity: O(n)
  */
  vector<int> smallerNumbersThanCurrent(vector<int> &nums)
  {
    const int n = nums.size();
    vector<int> sortedNums(nums);
    sort(begin(sortedNums), end(sortedNums));

    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
      ans[i] = distance(begin(sortedNums), lower_bound(begin(sortedNums), end(sortedNums), nums[i]));
    return ans;
  }
};