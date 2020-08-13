/*
1248. Count Number of Nice Subarrays

Level: Medium

https://leetcode.com/problems/count-number-of-nice-subarrays
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
  A subarray is called nice if there are k odd numbers on it.

  Solution: 
*/

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();

    int count = 0, ans = 0; 
    int find = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
      if (nums[i] % 2 == 1) // odd number
      {
        count++;
        if (count == k)
          find = 0;

        while (count == k)
        {
          find++;
          if (nums[j] % 2 == 1)
            count--;
          j++;
        }
      }
      ans += find;
    }

    return ans;
  }
};