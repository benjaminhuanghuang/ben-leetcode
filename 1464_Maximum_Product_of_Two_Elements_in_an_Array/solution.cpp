/*
1464. Maximum Product of Two Elements in an Array

Level: Easy

https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
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
    Time complexity: O(nlogn)
    Space complexity: O(1)
  */
  int maxProduct(vector<int> &nums)
  {
    sort(rbegin(nums), rend(nums));
    return (nums[0] - 1) * (nums[1] - 1);
  }

  /*
    Time complexity: O(n)
    Space complexity: O(1)
  */
  int maxProduct(vector<int>& nums) {
    int m1 = 0;
    int m2 = 0;
    for (int n : nums) {
      if (n > m1) {
        m2 = m1;
        m1 = n;
      } else if (n > m2) {
        m2 = n;
      }
    }
    return (m1 - 1) * (m2 - 1);
  }
};